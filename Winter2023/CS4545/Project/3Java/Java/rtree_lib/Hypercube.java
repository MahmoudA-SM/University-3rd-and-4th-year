public class Hypercube {
    // data members
    protected Point m_lower; // lower corner
    protected Point m_upper; // upper corner

    // constructor/destructor
    public Hypercube(int a_dimen, float[] a_l, float[] a_u) {
        m_lower = new Point(a_dimen, a_l);
        m_upper = new Point(a_dimen, a_u);
    }

    public Hypercube(Point a_lower, Point a_upper) {
        m_lower = new Point(a_lower);
        m_upper = new Point(a_upper);
    }

    public Hypercube(Hypercube a_hc) {
        m_lower = new Point(a_hc.m_lower);
        m_upper = new Point(a_hc.m_upper);
    }

    public void finalize() {
    }

    // assignment
    public Hypercube operator = (Hypercube
    a_hc)

    {
        m_lower = new Point(a_hc.m_lower);
        m_upper = new Point(a_hc.m_upper);
        return this;
    }

    // search
    public Point getLower() {
        return m_lower;
    }  // return the lower point

    public Point getUpper() {
        return m_upper;
    }  // return the upper point

    public Point getCenter() {        // return the center of the hypercube
        float[] center = new float[m_lower.dimen()];
        for (int i = 0; i < m_lower.dimen(); i++) {
            center[i] = (m_lower.coord(i) + m_upper.coord(i)) / 2;
        }
        return new Point(m_lower.dimen(), center);
    }

    public int dimen() {
        return m_lower.dimen();
    }  // return the dimensionality

    public float volume() {   // return the volume of the hypercube
        float vol = 1;
        for (int i = 0; i < m_lower.dimen(); i++) {
            vol *= (m_upper.coord(i) - m_lower.coord(i));
        }
        return vol;
    }

    public float perimeter() {  // return the perimeter of the hypercube
        float peri = 0;
        for (int i = 0; i < m_lower.dimen(); i++) {
            peri += 2 * (m_upper.coord(i) - m_lower.coord(i));
        }
        return peri;
    }

    // measures
    public float mindist(Hypercube a_hc) {    // min. distance to a hypercube
        float mind = 0;
        for (int i = 0; i < m_lower.dimen(); i++) {
            if (m_upper.coord(i) < a_hc.m_lower.coord(i))
                mind += (a_hc.m_lower.coord(i) - m_upper.coord(i)) * (a_hc.m_lower.coord(i) - m_upper.coord(i));
            else if (a_hc.m_upper.coord(i) < m_lower.coord(i))
                mind += (m_lower.coord(i) - a_hc.m_upper.coord(i)) * (m_lower.coord(i) - a_hc.m_upper.coord(i));
        }
        return (float) Math.sqrt(mind);
    }

    public float mindist(Point a_pt, int a_dimen) {
        float result = Float.MAX_VALUE;
        float dist;
        for (int i = 0; i < a_dimen; i++) {
            dist = Math.abs(a_pt.coord[i] - coord[i]);
            if (dist < result) {
                result = dist;
            }
        }
        return result;
    }

    public float diagdist() {
    }

    public boolean equals(Hypercube a_hc) {   // if it equals a hypercube
        // implementation here
    }

    public boolean enclose(Hypercube a_hc) {   // if it encloses a hypercube
        // implementation here
    }

    public boolean enclose(Point a_pt) {          // if it encloses a point
        // implementation here
    }

    public boolean equals(Hypercube other) {
        // implementation
    }

    public boolean enclose(Hypercube other) {
        // implementation
    }

    public boolean enclose(Point point) {
        // implementation
    }

    // intersection
    public boolean isIntersected(Hypercube hc0, Hypercube hc1) {
        // implementation
    }

    public boolean atRight(Hypercube hc0, Hypercube hc1) {
        // implementation
    }

    public boolean atAbove(Hypercube hc0, Hypercube hc1) {
        // implementation
    }

    public boolean atLeft(Hypercube hc0, Hypercube hc1) {
        // implementation
    }

    public boolean atBelow(Hypercube hc0, Hypercube hc1) {
        // implementation
    }

    public int EncloseWhichQuadrant(Hypercube hc0, Hypercube hc1, int[] qd_ID) {
        // implementation
    }

    public int inWhichStripe(Hypercube a_hc0, Hypercube a_hc1, int[] stripe) {
        // implementation
    }

    public int inWhichQuadrant(Hypercube a_hc0, Hypercube a_hc1, int[] quadrant) {
        // implementation
    }

    // operations
    public static Hypercube combine(Hypercube a_hc0, Hypercube a_hc1) {
        // implementation
    }

    public static Hypercube combine(Hypercube[] a_hcs, int a_count) {
        // implementation
    }

    public static Hypercube intersect(Hypercube a_hc0, Hypercube a_hc1) {
        // implementation
    }

    public static Hypercube intersect(Hypercube[] a_hcs, int a_count) {
        // implementation
    }

    public static Hypercube extend(Hypercube a_hc, float[] a_sidelen) {
        // implementation
    }

    public static int size(int a_dimen) {
        return 1 << a_dimen;
    }
}



