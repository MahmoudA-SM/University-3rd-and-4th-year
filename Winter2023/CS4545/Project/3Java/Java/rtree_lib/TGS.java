import java.util.ArrayList;



public class TGS {
    // bulk load a set of entries and form a Rtree
    public static Rtree bulkload(Memory a_memory, int a_dimen, int a_maxNodeFill, int a_maxLeafFill, int a_minNodeFill, int a_minLeafFill,
                            RtreeNodeEntry[] a_p, int a_numEntry, boolean a_pointOnly) {
    
    Rtree rtree = new Rtree(a_memory, a_dimen, a_maxNodeFill, a_maxLeafFill, a_minNodeFill, a_minLeafFill, a_pointOnly);
    int level = 0;
    while (true) {
        ArrayList<RtreeNodeEntry> a = new ArrayList<RtreeNodeEntry>();
        int r = partition(rtree, a_p, a_numEntry, level, a);
        for (int i = 0; i < a_numEntry; i++)
            a_p[i] = null;
        if (r == 1) {
            for (int i = 0; i < a.size(); i++)
                a.get(i).delete();
            break;
        } else {
            for (int i = 0; i < a.size(); i++)
                a_p[i] = a.get(i);
            a_numEntry = a.size();
            level++;
        }
    }
    return rtree;
}

    private static int partition(Rtree a_rtree, RtreeNodeEntry[] a_p, int a_numEntry, int a_level, ArrayList<RtreeNodeEntry> a) {
        int r = 0;
        int max = a_level == 0 ? a_rtree.m_maxLeafChild : a_rtree.m_maxNodeChild;
        if (a_numEntry <= max) {
            int pageid = a_rtree.m_memory.allocatePage();
            RtreeNode n = new RtreeNode(a_rtree, pageid, a_level, -1);
            for (int i = 0; i < a_numEntry; i++)
                n.insert(a_p[i]);
            a_rtree.m_memory.writePage(pageid, n);
            if (a_level > 0) {
                for (int i = 0; i < a_numEntry; i++) {
                    RtreeNode m = a_rtree.m_memory.loadPage(a_p[i].m_id);
                    m.m_parent = n.m_pageid;
                    a_rtree.m_memory.writePage(m.m_pageid, m);
                    m.delete();
                }
            }
            a.add(n.genNodeEntry());
            n.delete();
            a_rtree.m_memory.m_rootPageID = pageid;
            r = 1;
        } else {
            RtreeNodeEntry[] gp0 = new RtreeNodeEntry[a_numEntry];
            RtreeNodeEntry[] gp1 = new RtreeNodeEntry[a_numEntry];
            int cnt0 = 0, cnt1 = 0;

            a_p[0].packedSplit(a_p, a_numEntry, max, gp0, cnt0, gp1, cnt1);

            int r0 = partition(a_rtree, gp0, cnt0, a_level, a);
            int r1 = partition(a_rtree, gp1, cnt1, a_level, a);
            gp0 = null;
            gp1 = null;
            r = r0 + r1;
        }
        return r;
    }

}