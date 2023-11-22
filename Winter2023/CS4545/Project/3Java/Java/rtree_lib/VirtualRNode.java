public class VirtualRNode {

    public int m_pageid;
    public int m_level;
    public int m_parent;
    public int m_usedspace;
    public RtreeNodeEntry[] m_entry;

    public boolean m_isLeaf;

    public VirtualRNode() {
        m_pageid = 0;
        m_level = 0;
        m_parent = 0;
        m_usedspace = 0;
        m_entry = null;
        m_isLeaf = false;
    }

    public int copyData(final RtreeNode source) {
        // TODO: Implement copyData method
        m_pageid = source.m_pageid;
        m_level = source.m_level;
        m_parent = source.m_parent;
        m_usedspace = source.m_usedspace;
        m_isLeaf = source.isLeaf();
        return 0;    
    }

    public int copyData(final VirtualRNode source) {
        // TODO: Implement copyData method
        m_pageid = source.m_pageid;
        m_level = source.m_level;
        m_parent = source.m_parent;
        m_usedspace = source.m_usedspace;
        m_isLeaf = source.m_isLeaf;
        
        if (m_entry != null) {
            for (int i = 0; i < m_usedspace; i++) {
                m_entry[i].destroy();
            }
        } else {
            m_entry = new RtreeNodeEntry[m_usedspace];
        }
        for (int i = 0; i < m_usedspace; i++) {
            m_entry[i] = source.m_entry[i].clone();
        }
        
        return 0;
    }

    public int copyEntries(final RtreeNode source, final int numbers) {
        // TODO: Implement copyEntries method
        if (m_entry != null) {
            for (int i = 0; i < m_usedspace; i++) {
                m_entry[i].destroy();
            }
        } else {
            m_entry = new RtreeNodeEntry[numbers];
        }
        for (int i = 0; i < numbers; i++) {
            m_entry[i] = source.m_entry[i].clone();
        }
        m_usedspace = numbers;
        return 0;
    }

    public int insertEntry(final RtreeNodeEntry source) {
        // TODO: Implement insertEntry method
        if (m_entry != null) {
            for (int i = 0; i < m_usedspace; i++) {
                m_entry[i].destroy();
            }
        } else {
            m_entry = new RtreeNodeEntry[2];
        }
        m_pageid = source.m_id;
        m_level = 0;
        m_parent = 0;
        m_usedspace = 1;
        m_isLeaf = true;
        m_entry[0] = source.clone();
        return 0;
    }

    public int isLeaf() {
        // TODO: Implement isLeaf method
        return m_isLeaf ? 1 : 0;
    }

    public int displayMBR() {
        // TODO: Implement displayMBR method
        System.out.println(" stored id=" + m_entry[0].m_id);
        System.out.println("node x0:" + m_entry[0].m_hc.getLower()[0] +
                           " node y0:" + m_entry[0].m_hc.getUpper()[0] +
                           " node x1:" + m_entry[0].m_hc.getLower()[1] +
                           " node y1:" + m_entry[0].m_hc.getUpper()[1]);
        return 0;
    }

    public void destroy() {
        if (m_entry != null) {
            for (int i = 0; i < m_usedspace; i++) {
                m_entry[i].destroy();
            }
            m_entry = null;
        }
    }

}
