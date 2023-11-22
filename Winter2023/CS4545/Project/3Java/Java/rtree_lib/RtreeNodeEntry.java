// Java code for class RtreeNodeEntry

import java.nio.ByteBuffer;

public class RtreeNodeEntry {
    // data members
    public final int m_id;
    public Hypercube m_hc;
    public int num_records;

    // constructor/destructor
    public RtreeNodeEntry(int a_id, Hypercube a_hc) {
        m_id = a_id;
        m_hc = a_hc;
        num_records = 0;
    }

    public RtreeNodeEntry(int a_id, Hypercube a_hc, int num_nodes) {
        m_id = a_id;
        m_hc = a_hc;
        num_records = num_nodes;
    }

    public RtreeNodeEntry(RtreeNodeEntry other) {
        m_id = other.m_id;
        m_hc = new Hypercube(other.m_hc);
        num_records = other.num_records;
    }

    public RtreeNodeEntry clone() {
        return new RtreeNodeEntry(m_id, m_hc.clone());
    }
    public void RtreeNodeEntry() { }


    // comparison
    public boolean equals(RtreeNodeEntry a_entry) {
        return m_id == a_entry.m_id && m_hc.equals(a_entry.m_hc);
    }


    public boolean enclose(RtreeNodeEntry a_entry) {
        return m_hc.enclose(a_entry.m_hc);
    }

    // measures
    public float expansion(final RtreeNodeEntry a_entry) {
        final Hypercube hc = Hypercube.combine(m_hc, a_entry.m_hc);
        return hc.volume() - m_hc.volume();
    }


    // update
    // quadratic cost split SIGMOD84
    public int quadraticSplit(RtreeNodeEntry[] a_entry, int a_len, int a_split, RtreeNodeEntry[] a_gp0, int[] a_gp0cnt, RtreeNodeEntry[] a_gp1, int[] a_gp1cnt) {
        class Carrier {
            int m_dimen;
            RtreeNodeEntry m_p;

            public Carrier(int a_dimen, RtreeNodeEntry a_p) {
                m_dimen = a_dimen;
                m_p = a_p;
            }

            static int compareL(Object a_p0, Object a_p1) {
                Carrier c0 = (Carrier) a_p0;
                Carrier c1 = (Carrier) a_p1;
                float val0 = c0.m_p.m_hc.getLower()[c0.m_dimen];
                float val1 = c1.m_p.m_hc.getLower()[c1.m_dimen];
                if (val0 < val1) return -1;
                if (val0 > val1) return +1;
                return 0;
            }

            static int compareU(Object a_p0, Object a_p1) {
                Carrier c0 = (Carrier) a_p0;
                Carrier c1 = (Carrier) a_p1;
                float val0 = c0.m_p.m_hc.getUpper()[c0.m_dimen];
                float val1 = c1.m_p.m_hc.getUpper()[c1.m_dimen];
                if (val0 < val1) return -1;
                if (val0 > val1) return +1;
                return 0;
            }
        }
        int dimen = m_hc.dimen();
        float totalarea = -1;

        for (int d = 0; d < dimen; d++) {
            ArrayList<Carrier> listL = new ArrayList<>();
            ArrayList<Carrier> listU = new ArrayList<>();

            for (int i = 0; i < a_len; i++) {
                Carrier c = new Carrier(d, a_entry[i]);
                listL.add(c);
                listU.add(c);
            }

            Collections.sort(listL, Carrier.compareL);
            Collections.sort(listU, Carrier.compareU);

            Hypercube seed0 = listL.get(a_len - 1).m_p.m_hc;
            Hypercube seed1 = listU.get(0).m_p.m_hc;

            int cnt0 = 0, cnt1 = 0;
            RtreeNodeEntry[] tmp0 = new RtreeNodeEntry[a_len];
            RtreeNodeEntry[] tmp1 = new RtreeNodeEntry[a_len];

            for (int i = 0; i < a_len; i++) {
                Hypercube test0 = Hypercube.combine(seed0, a_entry[i].m_hc);
                Hypercube test1 = Hypercube.combine(seed1, a_entry[i].m_hc);

                if (cnt0 > a_len - a_split) {
                    tmp1[cnt1++] = a_entry[i];
                } else if (cnt1 > a_len - a_split) {
                    tmp0[cnt0++] = a_entry[i];
                } else {
                    if ((test0.volume() - seed0.volume()) < (test1.volume() - seed1.volume())) {
                        seed0 = test0;
                        tmp0[cnt0++] = a_entry[i];
                    } else {
                        seed1 = test1;
                        tmp1[cnt1++] = a_entry[i];
                    }
                }
            }
            float area = seed0.volume() + seed1.volume();

            if (area < totalarea || totalarea == -1) {
                a_gp0cnt = a_gp1cnt = 0;
                for (int i = 0; i < cnt0; i++) {
                    a_gp0[a_gp0cnt++] = tmp0[i];
                }
                for (int i = 0; i < cnt1; i++) {
                    a_gp1[a_gp1cnt++] = tmp1[i];
                }
                totalarea = area;
            }

            for (int i = 0; i < tmp0.length; i++) {
                tmp0[i] = null;
            }
            for (int i = 0; i < tmp1.length; i++) {
                tmp1[i] = null;
            }

            for (int i = 0; i < a_len; i++) {
                ((carrier) listL.get(i)).m_p = null;
                listL.set(i, null);
            }
            listL.clear();
            listU.clear();
        }
        return 0;
    }

    //// R*tree split algorithm VLDB90
//public int goodnessSplit(RtreeNodeEntry[] a_entry, int a_len, int a_split, RtreeNodeEntry[] a_gp0, int[] a_gp0cnt, RtreeNodeEntry[] a_gp1, int[] a_gp1cnt);
// split algorithm for TGS
    public static int packedSplit(RtreeNodeEntry[] a_entry, int a_len, int a_bulk, RtreeNodeEntry[] a_gp0, int[] a_gp0cnt, RtreeNodeEntry[] a_gp1, int[] a_gp1cnt) {
        int dimen = m_hc.dimen();
        float bestvol = -1;
        int bestcut = -1;
        int bestdim = -1;
        for (int d = 0; d < dimen; d++) {
            sortOnDimen(a_entry, a_len, d);
            int piece = a_len % a_bulk == 0 ? a_len / a_bulk : a_len / a_bulk + 1;
            int splitpt = piece / 2 * a_bulk;

            RtreeNodeEntry r0;
            RtreeNodeEntry r1;
            combine(a_entry[0], splitpt, 0, r0);
            combine(a_entry[splitpt], a_len - splitpt, 1, r1);

            float vol = r0.m_hc.volume() + r1.m_hc.volume();
            if (vol < bestvol || bestcut == -1) {
                bestdim = d;
                bestvol = vol;
                bestcut = splitpt;
            }
            r0 = null;
            r1 = null;
        }

        if (bestdim != dimen - 1) {
            sortOnDimen(a_entry, a_len, bestdim);
        }

        a_gp0cnt[0] = a_gp1cnt[0] = 0;
        for (int i = 0; i < a_len; i++) {
            if (i < bestcut) {
                a_gp0[a_gp0cnt[0]++] = a_entry[i];
            } else {
                a_gp1[a_gp1cnt[0]++] = a_entry[i];
            }
        }
        return 0;
    }
//// pick out entries for R*tree reintsertion
//public int pickWorst(RtreeNodeEntry[] a_entry, int a_len, int a_reinsert, RtreeNodeEntry[] a_gp0, int[] a_gp0cnt, RtreeNodeEntry[] a_gp1, int[] a_gp1cnt);

    // merge a number of entries into one
    public static int combine(RtreeNodeEntry[] a_entry, int a_len, int a_id, RtreeNodeEntry[] a_res) {
        int dimen = a_entry[0].m_hc.dimen();
        float[] cl = new float[dimen];
        float[] cu = new float[dimen];
        for (int d = 0; d < dimen; d++) {
            cl[d] = a_entry[0].m_hc.getLower()[d];
            cu[d] = a_entry[0].m_hc.getUpper()[d];
        }

        for (int i = 0; i < a_len; i++) {
            for (int d = 0; d < dimen; d++) {
                cl[d] = cl[d] < a_entry[i].m_hc.getLower()[d] ? cl[d] : a_entry[i].m_hc.getLower()[d];
                cu[d] = cu[d] > a_entry[i].m_hc.getUpper()[d] ? cu[d] : a_entry[i].m_hc.getUpper()[d];
            }
        }

        Hypercube hc = new Hypercube(dimen, cl, cu);
        a_res[0] = new RtreeNodeEntry(a_id, hc);
        return a_len;
    }

        // sort a number of entries along dimen
    public int sortOnDimen(RtreeNodeEntry[] a_entry, int a_len, int a_dimen) {
        dimenToSort = a_dimen;
        Arrays.sort(a_entry, 0, a_len, new Comparator<RtreeNodeEntry>() {
            @Override
            public int compare(RtreeNodeEntry o1, RtreeNodeEntry o2) {
                float o1Coord = o1.m_hc.getCoord(dimenToSort);
                float o2Coord = o2.m_hc.getCoord(dimenToSort);
                return Float.compare(o1Coord, o2Coord);
            }
        });
        return a_len;
    }

    int dimenToSort = 0;

    int compareDimen(final Object a0, final Object a1) {
        RtreeNodeEntry r0 = (RtreeNodeEntry) a0;
        RtreeNodeEntry r1 = (RtreeNodeEntry) a1;
        float v0 = r0.m_hc.getLower()[dimenToSort];
        float v1 = r1.m_hc.getLower()[dimenToSort];
        if (v0 < v1) {
            return -1;
        }
        if (v0 > v1) {
            return 1;
        }
        return 0;
    }

    // memory operations
    public int toMem(byte[] a_content, int a_len, boolean a_pt) {
        int init = a_len;
        System.arraycopy(ByteBuffer.allocate(4).putInt(m_id).array(), 0, a_content, a_len, 4);
        a_len += 4;
        System.arraycopy(ByteBuffer.allocate(4).putInt(num_records).array(), 0, a_content, a_len, 4);
        a_len += 4;

        for (int i = 0; i < m_hc.dimen(); i++) {
            float l = m_hc.getLower()[i];
            float u = m_hc.getUpper()[i];

            System.arraycopy(ByteBuffer.allocate(4).putFloat(l).array(), 0, a_content, a_len, 4);
            a_len += 4;
            if (!a_pt) {
                System.arraycopy(ByteBuffer.allocate(4).putFloat(u).array(), 0, a_content, a_len, 4);
                a_len += 4;
            }
        }
        return a_len - init;
    }


    // to convert a bytestring to a RtreeNodeEntry
    public static RtreeNodeEntry fromMem(byte[] a_content, int[] a_len, int dimen, boolean a_pt) {
        int id = ByteBuffer.wrap(Arrays.copyOfRange(a_content, a_len[0], a_len[0] + Integer.BYTES)).getInt();
        a_len[0] += Integer.BYTES;

        int num_nodes = ByteBuffer.wrap(Arrays.copyOfRange(a_content, a_len[0], a_len[0] + Integer.BYTES)).getInt();
        a_len[0] += Integer.BYTES;

        float[] cl = new float[dimen];
        float[] cu = new float[dimen];

        for (int i = 0; i < dimen; i++) {
            cl[i] = ByteBuffer.wrap(Arrays.copyOfRange(a_content, a_len[0], a_len[0] + Float.BYTES)).getFloat();
            a_len[0] += Float.BYTES;

            cu[i] = cl[i];
            if (!a_pt) {
                cu[i] = ByteBuffer.wrap(Arrays.copyOfRange(a_content, a_len[0], a_len[0] + Float.BYTES)).getFloat();
                a_len[0] += Float.BYTES;
            }
        }

        Hypercube hc = new Hypercube(dimen, cl, cu);
        return new RtreeNodeEntry(id, hc, num_nodes);
    }


    // info: storage size
    public static int size(final int a_dimen, final boolean isPoint) {
        if (isPoint) {
            return Integer.BYTES + Hypercube.size(a_dimen) / 2;
        }
        return Integer.BYTES + Hypercube.size(a_dimen) + Integer.BYTES;
    }
}
