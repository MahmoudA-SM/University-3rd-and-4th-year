
public abstract class testInterface{
    public static double triArea(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return Math.sqrt(p * (p - a) * (p - b) * (p - c));
}

public static void testVolume() {
    // in 3 dimension
    // double volumn_at_half_inter(const realT *pointCoordinates, int p_num, vector<float> &innerPoint);
    int dim = 3;
    int halfspace_num = 3 + 1;
    // three points that intersect with user preference:
    // A(0.3, 0.6, 0.1), B(0.2, 0.3, 0.5), C(0.4, 0.4, 0.2)
    // AB^2=0.26, AC^2=0.06, BC^2=0.14
    // area \approximateEqual 0.0433
    // volume \approximateEqual 1/3 * \sqrt{3}
    // n1 * A =0, n1 * B =0
    // n1=\lambda_1 * (-27/13, 1, 3/13)
    // n2 * A =0, n2 * C =0
    // n2=\lambda_2 * (-4, 1, 6)
    // n3 * B =0, n3 * C =0
    // n3=\lambda_3 * (7/8, 1, -1/4)
    // an obvious interior point
    // D(0.3/2, 1.3/3/2, 0.8/3/2)
    // n1 * D < 0, n2 * D >0, n3*D>0
    // thereby, the halfspace expression of the three points and (0, 0, 0) will be:
    // {w| n1 * w <=0, -n2 * w<=0, -n3 * w <=0, \vec{1} * w<=-(-1)}
    double[] pointCoordinates = new double[(dim + 1) * halfspace_num];
    pointCoordinates[0] = -27.0 / 13;
    pointCoordinates[1] = 1;
    pointCoordinates[2] = 3.0 / 13;
    pointCoordinates[3] = 0;
    pointCoordinates[4] = 4;
    pointCoordinates[5] = -1;
    pointCoordinates[6] = -6;
    pointCoordinates[7] = 0;
    pointCoordinates[8] = -7.0 / 8;
    pointCoordinates[9] = -1;
    pointCoordinates[10] = 1.0 / 4;
    pointCoordinates[11] = 0;
    pointCoordinates[12] = 1;
    pointCoordinates[13] = 1;
    pointCoordinates[14] = 1;
    pointCoordinates[15] = -1;
    ArrayList<Float> innerPoint = new ArrayList<Float>(Arrays.asList((float)(0.3/2), (float)(1.3/3/2), (float)(0.8/3/2)));
    QhullUser qu = new QhullUser();

    System.out.println(qu.volumnAtHalfInter(pointCoordinates, halfspace_num, innerPoint));
    // You can declare this function inside an abstract class or interface depending on your specific use case.
    // You can also replace "System.out.println" with "logger.info" or any other logging statement as per your needs.
    // You may also need to import relevant classes such as ArrayList and Arrays.
    // Also, make
}

public void testHalfspace() {
    // in 3 dimension
    // double volumn_at_half_inter(const realT *pointCoordinates, int p_num, vector<float> &innerPoint);
    int dim = 3;
    int pnum_num = 3 + 1;
    // three points that intersect with user preference:
    // A(0.3, 0.6, 0.1), B(0.2, 0.3, 0.5), C(0.4, 0.4, 0.2)
    // AB^2=0.26, AC^2=0.06, BC^2=0.14
    // area \appraximateEqual 0.0433
    // volume \apparaximateEqual 1/3 * \sqrt{3}
    // n1 * A =0, n1 * B =0
    // n1=\lambda_1 * (-27/13, 1, 3/13)
    // n2 * A =0, n2 * C =0
    // n2=\lambda_2 * (-4, 1, 6)
    // n3 * B =0, n3 * C =0
    // n3=\lambda_3 * (7/8, 1, -1/4)
    // an obvious interior point
    // D(0.3/2, 1.3/3/2, 0.8/3/2)
    // n1 * D > 0, n2 * D >0, n3*D>0
    // thereby, the halfspace expression of the three points and (0, 0, 0) will be:
    // {w| -n1 * w <=0, -n2 * w<=0, -n3 * w <=0, \vec{1} * w<=-(-1)}
    double[] pointCoordinates = new double[(dim)*pnum_num];
    pointCoordinates[0] = 0;
    pointCoordinates[1] = 0;
    pointCoordinates[2] = 0;
    pointCoordinates[3] = 0.3;
    pointCoordinates[4] = 0.6;
    pointCoordinates[5] = 0.1;
    pointCoordinates[6] = 0.2;
    pointCoordinates[7] = 0.3;
    pointCoordinates[8] = 0.5;
    pointCoordinates[9] = 0.4;
    pointCoordinates[10] = 0.4;
    pointCoordinates[11] = 0.2;
    //    pointCoordinates[12]=1;
    //    pointCoordinates[13]=1;
    //    pointCoordinates[14]=1;
    //    pointCoordinates[15]=-1;
    List<Float> innerPoint = new ArrayList<>(Arrays.asList((float) (0.3/2), (float) (1.3/3/2), (float) (0.8/3/2)));
    qhull_user qu = new qhull_user();
    Qhull q = new Qhull();
    StringWriter output = new StringWriter();
    q.runQhull("normals of square", dim, pnum_num, pointCoordinates, "QJ"); // halfspace intersect

    output.getBuffer().setLength(0);
    q.outputQhull(output);
    System.out.println("debug: after trying to get volume");
    System.out.println(output.toString());
    //   
}
}