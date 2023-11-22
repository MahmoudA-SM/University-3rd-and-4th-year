//
// Created by Keming Li on 2023/1/12.
//

#ifndef IPREF_TEST_H
#define IPREF_TEST_H
#include "qhull_user.h"
#include <vector>
double tri_area(double a, double b, double c){
    double p=(a+b+c)/2.0;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

void test_volume(){
    // in 3 dimension
//    double volumn_at_half_inter(const realT *pointCoordinates, int p_num, vector<float> &innerPoint);
    uint32_t dim=3;
    uint32_t halfspace_num=3+1;
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
    // n1 * D < 0, n2 * D >0, n3*D>0
    // thereby, the halfspace expression of the three points and (0, 0, 0) will be:
    // {w| n1 * w <=0, -n2 * w<=0, -n3 * w <=0, \vec{1} * w<=-(-1)}
    realT *pointCoordinates=new realT[(dim+1)*halfspace_num];
    pointCoordinates[0]=-27.0/13;
    pointCoordinates[1]=1;
    pointCoordinates[2]=3.0/13;
    pointCoordinates[3]=0;
    pointCoordinates[4]=4;
    pointCoordinates[5]=-1;
    pointCoordinates[6]=-6;
    pointCoordinates[7]=0;
    pointCoordinates[8]=-7.0/8;
    pointCoordinates[9]=-1;
    pointCoordinates[10]=1.0/4;
    pointCoordinates[11]=0;
    pointCoordinates[12]=1;
    pointCoordinates[13]=1;
    pointCoordinates[14]=1;
    pointCoordinates[15]=-1;
    std::vector<float> innerPoint{0.3/2, 1.3/3/2, 0.8/3/2};
    qhull_user qu;

//    qhT qh_qh;                /* Qhull's data structure.  First argument of most calls */
//    qhT* qh = &qh_qh;
//    QHULL_LIB_CHECK
//    qh_zero(qh, NULL);
//    fflush(NULL);

    cout<<qu.volumn_at_half_inter(pointCoordinates, halfspace_num, innerPoint)<<endl;
    delete [] (pointCoordinates);
}


void test_halfspace(){
    // in 3 dimension
//    double volumn_at_half_inter(const realT *pointCoordinates, int p_num, vector<float> &innerPoint);
    uint32_t dim=3;
    uint32_t pnum_num=3+1;
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
    realT *pointCoordinates=new realT[(dim)*pnum_num];
    pointCoordinates[0]=0;
    pointCoordinates[1]=0;
    pointCoordinates[2]=0;
    pointCoordinates[3]=.3;
    pointCoordinates[4]=.6;
    pointCoordinates[5]=.1;
    pointCoordinates[6]=.2;
    pointCoordinates[7]=.3;
    pointCoordinates[8]=.5;
    pointCoordinates[9]=.4;
    pointCoordinates[10]=.4;
    pointCoordinates[11]=.2;
//    pointCoordinates[12]=1;
//    pointCoordinates[13]=1;
//    pointCoordinates[14]=1;
//    pointCoordinates[15]=-1;
    std::vector<float> innerPoint{0.3/2, 1.3/3/2, 0.8/3/2};
    qhull_user qu;
    Qhull q;
    std::stringstream output;
    q.runQhull("normals of square", dim, pnum_num, pointCoordinates, "QJ"); // halfspace intersect


    output.clear();
    q.outputQhull("n");
    cout<<"debug: after trying to get volume"<<endl;
    cout<<output.str()<<endl;
//    qhT qh_qh;                /* Qhull's data structure.  First argument of most calls */
//    qhT* qh = &qh_qh;
//    QHULL_LIB_CHECK
//    qh_zero(qh, NULL);
//    fflush(NULL);

    delete [] (pointCoordinates);
}
#endif //IPREF_TEST_H
