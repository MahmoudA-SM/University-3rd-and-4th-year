/*----------------------------------------------------------------------------
This class represents d-dimensional points
---------------------------------------------------------------------------- */

public class Point {
    // data members
    private int m_dimen;               // dimensionality
    private float[] m_coor;           // dimensional values

    // constructors
    public Point() {}

    public Point(int a_dimen, float[] a_coor) {
        m_dimen = a_dimen;
        m_coor = new float[m_dimen];
        if (a_coor != null) {
            System.arraycopy(a_coor, 0, m_coor, 0, m_dimen);
        } else {
            Arrays.fill(m_coor, 0f);
        }
    }

    public Point(Point a_pt) {
        m_dimen = a_pt.m_dimen;
        m_coor = new float[m_dimen];
        System.arraycopy(a_pt.m_coor, 0, m_coor, 0, m_dimen);
    }

    // assignment
    public Point set(Point a_pt) {
        m_dimen = a_pt.m_dimen;
        System.arraycopy(a_pt.m_coor, 0, m_coor, 0, m_dimen);
        return this;
    }

    // search
    public float get(int a_i) {
        return m_coor[a_i];
    }

    public static Point midpoint(Point a_p0, Point a_p1) {
        float[] m = new float[a_p0.m_dimen];
        for (int i = 0; i < a_p0.m_dimen; i++)
            m[i] = (a_p0.m_coor[i] + a_p1.m_coor[i]) / 2;
        return new Point(a_p0.m_dimen, m);
    }

    public float get(int a_i) {
        return m_coor[a_i];
    }
    // update
    public void set(int i, float c) {
        m_coor[i] = c;
    }


    // measures
    public float distance(Point a_pt) {
        float dist = 0;
        for (int d = 0; d < m_dimen; d++) {
            float diff = (a_pt.m_coor[d] - m_coor[d]);
            dist += diff * diff;
        }
        return (float) Math.sqrt(dist);
    }


    // comparison
    public boolean equals(Point a_pt) {
        for (int d = 0; d < m_dimen; d++) {
            if (m_coor[d] != a_pt.m_coor[d]) {
                return false;
            }
        }
        return true;
    }


    public static int size(int dimen) {
        return Float.BYTES * dimen;
    }


}
