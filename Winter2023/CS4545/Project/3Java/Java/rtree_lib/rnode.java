public class rnode{
    // data members
    public final Rtree m_rtree; // reference to Rtree
    public final int m_pageid; // page ID of the node
    public final int m_level; // level in the tree (0:leaf)
    public final int m_parent; // page ID of its parent node
    public int m_usedspace; // number of entries
    public RtreeNodeEntry[] m_entry; // an array of entries
    // constants
    public static final int NODE_UNCHANGED = 10000;  // value for node whose content unchanged
    public static final int NODE_CHANGED = 10001;    // value for node content change
    public static final int NODE_OVERFLOW = 10002;   // value for node overflow
    public static final int NODE_UNDERFULL = 10003;  // value for node underfull

    // constructor
    public RtreeNode(final Rtree a_tree, final int a_pageid, final int a_level, final int a_parent) {
        m_rtree = a_tree;
        m_pageid = a_pageid;
        m_level = a_level;
        m_parent = a_parent;
        m_usedspace = 0;
        m_entry = new RtreeNodeEntry[m_rtree.m_maxNodeEntries];
        for (int i = 0; i < m_rtree.m_maxNodeEntries; i++) {
            m_entry[i] = new RtreeNodeEntry(m_rtree.m_dimen, m_rtree.m_store);
        }
    }
    protected void finalize() throws Throwable {
        for (int i = 0; i < m_usedspace; i++)
            m_entry[i].finalize();
        m_entry = null;
        super.finalize();
    }



    public RtreeNode(final int a_pageid, final int a_level, final int a_parent) {
        m_pageid = a_pageid;
        m_level = a_level;
        m_parent = a_parent;
        m_usedspace = 0;
        int max = 2;
        m_entry = new RtreeNodeEntry[max];
        Arrays.fill(m_entry, null);
    }

    public RtreeNode(final RtreeNode node) {
        m_rtree = node.m_rtree;
        m_pageid = node.m_pageid;
        m_level = node.m_level;
        m_parent = node.m_parent;
        m_usedspace = node.m_usedspace;
        m_entry = new RtreeNodeEntry[m_rtree.m_maxNodeEntries];
        for (int i = 0; i < m_rtree.m_maxNodeEntries; i++) {
            m_entry[i] = new RtreeNodeEntry(node.m_entry[i]);
        }
    }

    public RtreeNode(final Rtree a_rtree, final int a_pageid, final int a_level, final int a_parent) {
        this.m_rtree = a_rtree;
        this.m_pageid = a_pageid;
        this.m_level = a_level;
        this.m_parent = a_parent;
        this.m_usedspace = 0;
        final int max = (m_level == 0 ? m_rtree.m_maxLeafChild : m_rtree.m_maxNodeChild) + 1;
        m_entry = new RtreeNodeEntry[max];
        Arrays.fill(m_entry, null);
    }


    //search function
    public boolean isRoot() {
        return m_parent == -1;
    }


    public boolean isLeaf() {
        return m_level == 0;
    }


    RtreeNodeEntry genNodeEntry() {
        RtreeNodeEntry newentry = null;
        if (m_usedspace > 0) {
            m_entry[0].combine(m_entry, m_usedspace, m_pageid, newentry);
        }
        return newentry;
    }

    public RtreeNode clone() {
        RtreeNode node = new RtreeNode(m_rtree, m_pageid, m_level, m_parent);
        for (int i = 0; i < m_usedspace; i++) {
            node.m_entry[node.m_usedspace++] = m_entry[i].clone();
        }
        return node;
    }


    public int insert(RtreeNodeEntry a_entry) {
        int status = NODE_UNCHANGED;
        m_entry[m_usedspace++] = a_entry.clone();
        int max = (m_level == 0 ? m_rtree.m_maxNodeChild : m_rtree.m_maxNodeChild) + 1;
        if (m_usedspace == max) {
            status = NODE_OVERFLOW;
        } else {
            RtreeNodeEntry oldentry;
            m_entry[0].combine(m_entry, m_usedspace - 1, m_pageid, oldentry);
            RtreeNodeEntry newentry;
            m_entry[0].combine(m_entry, m_usedspace, m_pageid, newentry);
            status = oldentry.equals(newentry) ? NODE_CHANGED : status;
        }
        return status;
    }


    public void quadraticSplit(RtreeNode[] a_p0, RtreeNode[] a_p1) {
        int split = m_level > 0 ? m_rtree.m_minNodeChild : m_rtree.m_minLeafChild;
        a_p0[0] = new RtreeNode(m_rtree, -1, m_level, m_parent);
        a_p1[0] = new RtreeNode(m_rtree, -1, m_level, m_parent);
        m_entry[0].quadraticSplit(m_entry, m_usedspace, split, a_p0[0].m_entry, a_p0[0].m_usedspace, a_p1[0].m_entry, a_p1[0].m_usedspace);
    }


    public int replace(RtreeNodeEntry a_entry) {
        int status = NODE_UNCHANGED;
        for (int i = 0; i < m_usedspace; i++) {
            if (m_entry[i].m_id == a_entry.m_id) {
                if (!m_entry[i].equals(a_entry)) {
                    status = NODE_CHANGED;
                }
                m_entry[i] = a_entry.clone();
                break;
            }
        }
        return status;
    }

    public int remove(RtreeNodeEntry a_entry) {
        int status = NODE_UNCHANGED;
        int found = -1;
        for (int i = 0; i < m_usedspace && found == -1; i++) {
            if (m_entry[i].m_id == a_entry.m_id) {
                found = i;
            }
        }

        if (found != -1) {
            int min = (m_level == 0 ? m_rtree.m_minLeafChild : m_rtree.m_minNodeChild) + 1;
            if (m_usedspace <= min) {
                m_entry[found] = m_entry[--m_usedspace];
                status = NODE_UNDERFULL;
            } else {
                RtreeNodeEntry oldentry;
                m_entry[0].combine(m_entry, m_usedspace, m_pageid, oldentry);
                m_entry[found] = m_entry[--m_usedspace];

                RtreeNodeEntry newentry;
                m_entry[0].combine(m_entry, m_usedspace, m_pageid, newentry);

                status = oldentry.equals(newentry) ? status : NODE_CHANGED;
            }
        }
        return status;
    }


    //memory operations
    public int toMem(byte[] content, int len) {
        ByteBuffer buffer = ByteBuffer.wrap(content, len, content.length - len);
        buffer.putInt(m_pageid);
        buffer.putInt(m_level);
        buffer.putInt(m_parent);
        buffer.putInt(m_usedspace);

        for (int i = 0; i < m_usedspace; i++) {
            int elen = 0;
            m_entry[i].toMem(buffer.array(), buffer.position(), m_level == 0 && m_rtree.m_pointOnly);
            buffer.position(buffer.position() + elen);
        }
        return buffer.position() - len;
    }

        public static RtreeNode fromMem(byte[] a_p, int[] a_len, Rtree a_rtree, Function3<byte[], Integer, Boolean, RtreeNodeEntry> fromMem) {
        int pageid, level, parent, usedSpace, dimen;
        dimen = a_rtree.m_dimen;
        ByteBuffer buffer = ByteBuffer.wrap(a_p);
        buffer.position(a_len[0]);
        pageid = buffer.getInt();
        a_len[0] += 4;
        level = buffer.getInt();
        a_len[0] += 4;
        parent = buffer.getInt();
        a_len[0] += 4;
        usedSpace = buffer.getInt();
        a_len[0] += 4;

        RtreeNode node = new RtreeNode(a_rtree, pageid, level, parent);

        for (int i = 0; i < usedSpace; i++) {
            RtreeNodeEntry e = fromMem.apply(a_p, a_len[0], level == 0 && a_rtree.m_pointOnly);
            node.m_entry[node.m_usedspace++] = e;
        }

        return node;
    }


    //info
    public static int size() {
        return 4 * Integer.BYTES;
    }


}