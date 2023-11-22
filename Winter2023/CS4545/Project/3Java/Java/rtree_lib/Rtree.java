public class Rtree {
    // data members
    public Memory m_memory;         // reference to mem that stores this rtree
    public final int m_dimen;      // no. of dimensions
    public final int m_maxNodeChild;   // max. number of entries in a node
    public final int m_minNodeChild;   // min. number of entries in a node
    public final int m_maxLeafChild;   // max. number of entries in a node
    public final int m_minLeafChild;   // min. number of entries in a node
    public boolean m_pointOnly;    // indicate if the Rtree stores only points

    // constructors / destructor
    public Rtree(Memory a_memory, int a_dimen, int a_maxNodefill, int a_maxLeafFill, int a_minNodeFill, int a_minLeafFill, boolean a_pointOnly) {
        m_memory = a_memory;
        m_dimen = a_dimen;
        m_maxNodeChild = a_maxNodefill;
        m_maxLeafChild = a_maxLeafFill;
        m_minNodeChild = a_minNodeFill;
        m_minLeafChild = a_minLeafFill;
        m_pointOnly = a_pointOnly;
    }

    public Rtree(Memory a_memory, int a_dimen, int a_maxNodefill, int a_maxLeafFill, int a_minNodeFill, int a_minLeafFill) {
        this(a_memory, a_dimen, a_maxNodefill, a_maxLeafFill, a_minNodeFill, a_minLeafFill, false);
    }

    // update methods
    public int insert(RtreeNodeEntry a_entry, int a_level) {  // add an entry to Rtree at a specified level (default:0)
        // implementation goes here
        if (m_memory.m_rootPageID == -1) { // no tree exists
            m_memory.m_rootPageID = m_memory.allocatePage();
            RtreeNode n = new RtreeNode(this, m_memory.m_rootPageID);
            n.insert(a_entry);
            m_memory.writePage(m_memory.m_rootPageID, n);
        } else {
            RtreeNode n = chooseLeaf(a_entry, a_level);
            int status = n.insert(a_entry);
            if (a_level > 0) {
                RtreeNode m = m_memory.loadPage(a_entry.m_id);
                m.m_parent = n.m_pageid;
                m_memory.writePage(m.m_pageid, m);
                m = null;
            }
            while (status != NODE_UNCHANGED) {
                RtreeNode parent = null;
                switch (status) {
                    case NODE_OVERFLOW: {
                        RtreeNode n0, n1;
                        n.quadraticSplit(n0, n1);
                        n0.m_pageid = n.m_pageid;
                        n1.m_pageid = m_memory.allocatePage();
                        n.m_usedspace = 0; // reset the usedspace since all entries are moved to split nodes
                        if (!n.isLeaf()) {
                            for (int i = 0; i < n0.m_usedspace; i++) {
                                int id = n0.m_entry[i].m_id;
                                RtreeNode * child = m_memory.loadPage(id);
                                child.m_parent = n0.m_pageid;
                                m_memory.writePage(id, child);
                                delete child;
                            }
                            for (int i = 0; i < n1.m_usedspace; i++) {
                                int id = n1.m_entry[i].m_id;
                                RtreeNode * child = m_memory.loadPage(id);
                                child.m_parent = n1.m_pageid;
                                m_memory.writePage(id, child);
                                delete child;
                            }
                        }

                        RtreeNode parent;
                        if (n.isRoot()) {
                            int parentid = m_memory.allocatePage();
                            m_memory.m_rootPageID = parentid;
                            parent = new RtreeNode(this, parentid, n.m_level + 1, -1);

                            RtreeNodeEntry * e0 = n0.genNodeEntry();
                            n0.m_parent = parentid;
                            parent.insert(e0);

                            RtreeNodeEntry * e1 = n1.genNodeEntry();
                            n1.m_parent = parentid;
                            parent.insert(e1);

                            m_memory.writePage(n0.m_pageid, n0);
                            m_memory.writePage(n1.m_pageid, n1);

                            status = NODE_UNCHANGED;
                            delete e0;
                            delete e1;
                        } else {
                            parent = m_memory.loadPage(n.m_parent);
                            RtreeNodeEntry * e0 = n0.genNodeEntry();
                            n0.m_parent = parent -> m_pageid;
                            int status1 = parent.replace(e0);

                            RtreeNodeEntry * e1 = n1.genNodeEntry();
                            n1.m_parent = parent -> m_pageid;
                            int status2 = parent.replace(e1);

                            m_memory.writePage(n0.m_pageid, n0);
                            m_memory.writePage(n1.m_pageid, n1);
                            status = status2;
                            if (status != NODE_OVERFLOW && status1 == NODE_CHANGED) {
                                status = NODE_CHANGED;
                            }
                            delete e0;
                            delete e1;
                        }
                        delete parent;
                        break;

                    }
                    case NODE_CHANGED: {
                        if (n.isRoot()) {
                            status = NODE_UNCHANGED;
                            parent = n.clone();
                            break;
                        } else {
                            parent = m_memory.loadPage(n.m_parent);
                            RtreeNodeEntry e = n.genNodeEntry();
                            status = parent.replace(e);
                            m_memory.writePage(n.m_pageid, n);
                            e.delete();
                        }
                    }
                }
                n.delete();
                n = parent;
            }
            m_memory.writePage(n.m_pageid, n);
            n.delete();
            return 0;
        }
    }

    public int insert(RtreeNodeEntry a_entry) {
        return insert(a_entry, 0);
    }

    public int remove(RtreeNodeEntry a_entry) {
        class carrier {
            final int m_level;
            final RtreeNodeEntry m_entry;

            carrier(int a_level, RtreeNodeEntry a_entry) {
                m_level = a_level;
                m_entry = a_entry;
            }
        }

        RtreeNode n = locateLeaf(a_entry);
        if (n == null) {
            return 0;
        }

        Array a = new Array();
        int status = n.remove(a_entry);

        while (!n.isRoot()) {
            if (status == NODE_UNCHANGED) {
                m_memory.writePage(n.m_pageid, n);
                break;
            }

            if (status == NODE_CHANGED) {
                RtreeNode parent = m_memory.loadPage(n.m_parent);
                RtreeNodeEntry e = n.genNodeEntry();
                status = parent.replace(e);
                m_memory.writePage(n.m_pageid, n);
                delete e;
                delete n;
                n = parent;
            } else if (status == NODE_UNDERFULL) {
                RtreeNode parent = m_memory.loadPage(n.m_parent);
                for (int i = 0; i < n.m_usedspace; i++) {
                    a.append(new carrier(n.m_level, n.m_entry[i].clone()));
                }
                RtreeNodeEntry e = n.genNodeEntry();
                status = parent.remove(e);
                m_memory.removePage(n.m_pageid);
                delete e;
                delete n;
                n = parent;
            }
        }

        if (n.isRoot()) {
            if (n.m_usedspace == 1 && !n.isLeaf()) {
                m_memory.removePage(n.m_pageid);
                m_memory.m_rootPageID = n.m_entry[0].m_id;
                RtreeNode child = m_memory.loadPage(n.m_entry[0].m_id);
                child.m_parent = -1;
                m_memory.writePage(child.m_pageid, child);
                delete child;
            } else {
                m_memory.writePage(n.m_pageid, n);
            }
        }
        delete n;

        for (int i = 0; i < a.size(); i++) {
            carrier c = (carrier)a[i];
            insert(c.m_entry, c.m_level);
            delete c.m_entry;
            delete c;
        }

        return 0;
    }


    // test methods
    public boolean integrityTest() {
// this function tests the Rtree structure that
// 1) the entries kept in the parent node matches exactly the child nodes and
// 2) the level of the node is 1 less than that of its parent
        class Carrier {
            public final int m_pageid; // page id
            public final int m_level; // node level
            public RtreeNodeEntry m_e; // entry at the parent

            public Carrier(int a_pageid, int a_level, RtreeNodeEntry a_e) {
                m_pageid = a_pageid;
                m_level = a_level;
                m_e = a_e;
            }
        }

        boolean result = true;
        Stack<Carrier> s = new Stack<>();
        s.push(new Carrier(m_memory.m_rootPageID, 0, null));
        while (!s.isEmpty()) {
            Carrier c = s.pop();
            RtreeNode n = m_memory.loadPage(c.m_pageid);
            if (c.m_e != null) {
                RtreeNodeEntry e = n.genNodeEntry();
                if (!e.equals(c.m_e))
                    result = false;
                if (n.m_level != c.m_level)
                    result = false;
                delete e;
                delete c.m_e;
            }
            for (int i = 0; i < n.m_usedspace && !n.isLeaf(); i++)
                s.push(new Carrier(n.m_entry[i].m_id, n.m_level - 1, n.m_entry[i].clone()));
            delete n;
            delete c;
        }
        return true;
    }

        public Hash loadObjects() {
        Hash h = new Hash(10000);
        Stack s = new Stack();
        s.push((Object)m_memory.m_rootPageID);
        while (!s.isEmpty()) {
            int pageid = (int)(Integer)s.pop();
            RtreeNode n = m_memory.loadPage(pageid);
            if (n.isLeaf()) {
                for (int i = 0; i < n.m_usedspace; i++) {
                    RtreeNodeEntry e = (RtreeNodeEntry)h.get(n.m_entry[i].m_id);
                    if (e != null) {
// duplicate
                        System.out.println("duplicate insertion of object " + n.m_entry[i].m_id);
                    }
                    h.put(n.m_entry[i].m_id, n.m_entry[i].clone());
                }
            } else {
                for (int i = 0; i < n.m_usedspace; i++) {
                    s.push((Object)n.m_entry[i].m_id);
                }
            }
            delete n;
        }
        return h;
    }

    public float nodeVolume(final int a_level) {
        float vol = 0;
        Stack s = new Stack();
        s.push(m_memory.m_rootPageID);
        while (!s.isEmpty()) {
            int pageid = (int) s.pop();
            RtreeNode n = m_memory.loadPage(pageid);
            if (n.m_level > a_level) {
                if (n.m_level == a_level + 1) {
                    for (int i = 0; i < n.m_usedspace; i++)
                        vol += n.m_entry[i].m_hc.volume();
                } else {
                    for (int i = 0; i < n.m_usedspace; i++)
                        s.push(n.m_entry[i].m_id);
                }
            }
            n = null; // free memory
        }
        return vol;
    }





    public float nodePerimeter(final int a_level) {
        float peri = 0;
        Stack s = new Stack();
        s.push(m_memory.m_rootPageID);
        while (!s.isEmpty()) {
            int pageid = (int)s.pop();
            RtreeNode n = m_memory.loadPage(pageid);
            if (n.m_level > a_level) {
                if (n.m_level == a_level + 1)
                    for (int i = 0; i < n.m_usedspace; i++)
                        peri += n.m_entry[i].m_hc.perimeter();
                else
                    for (int i = 0; i < n.m_usedspace; i++)
                        s.push(n.m_entry[i].m_id);
            }
            n = null;
        }
        return peri;
    }


    public int nodeCount(final int a_level) {
        int cnt = 0;
        Stack s = new Stack();
        s.push(m_memory.m_rootPageID);

        while (!s.empty()) {
            final int pageid = (int) s.pop();
            final RtreeNode n = m_memory.loadPage(pageid);

            if (n.m_level > a_level) {
                if (n.m_level == a_level + 1)
                    cnt += n.m_usedspace;
                else
                    for (int i = 0; i < n.m_usedspace; i++)
                        s.push(n.m_entry[i].m_id);
            }

            m_memory.deletePage(n);
        }

        return cnt;
    }


    // helper methods
    public RtreeNode chooseLeaf(RtreeNodeEntry a_entry, int a_level) {
        RtreeNode root = m_memory.loadPage(m_memory.m_rootPageID);
        while (root.m_level > a_level) {
            int candidate = root.m_entry[0].m_id;
            float enlargement = root.m_entry[0].expansion(a_entry);
            for (int i = 1; i < root.m_usedspace; i++) {
                float exp = root.m_entry[i].expansion(a_entry);
                if (exp < enlargement) {
                    enlargement = exp;
                    candidate = root.m_entry[i].m_id;
                }
            }
            root.delete();
            root = m_memory.loadPage(candidate);
        }
        return root;
    }


    public RtreeNode locateLeaf(RtreeNodeEntry a_entry) {
        int result = -1;
        Stack<Object> s = new Stack<>();
        s.push(m_memory.m_rootPageID);
        while (!s.isEmpty()) {
            int pageid = (int) s.pop();
            if (result == -1) {
                RtreeNode n = m_memory.loadPage(pageid);
                if (n.isLeaf()) {
                    for (int i = 0; i < n.m_usedspace; i++) {
                        if (n.m_entry[i].equals(a_entry))
                            result = pageid;
                    }
                } else {
                    for (int i = 0; i < n.m_usedspace; i++) {
                        if (n.m_entry[i].enclose(a_entry))
                            s.push(n.m_entry[i].m_id);
                    }
                }
                n = null;
            }
        }
        if (result == -1)
            return null;
        return m_memory.loadPage(result);
    }

}

class Memory {
    private Rtree m_rtree;

    public void setRtree(Rtree rtree) {
        m_rtree = rtree;
    }
}