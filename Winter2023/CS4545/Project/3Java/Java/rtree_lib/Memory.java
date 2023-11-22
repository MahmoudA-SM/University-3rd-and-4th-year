
public abstract class Memory {

    // Data members
    public Rtree m_rtree;       // R-tree
    public int m_rootPageID;    // root page
    public final int m_pagesize; // page size

    // Constructor
    public Memory(final int a_pagesize) {
        m_rootPageID = -1;
        m_pagesize = a_pagesize;
    }

    // Abstract methods
    public abstract RtreeNode loadPage(final int a_pageID);
    public abstract int allocatePage();
    public abstract void writePage(final int a_pageID, final RtreeNode m_p);
    public abstract void removePage(final int a_pageID);
    public abstract void flush();
}