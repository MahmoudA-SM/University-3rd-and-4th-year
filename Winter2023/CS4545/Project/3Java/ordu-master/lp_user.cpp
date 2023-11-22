
#include "lp_user.h"
#include <lp_lib.h>
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

void lpModel(lprec* lp, int& dimen)
{
    if (lp == nullptr)
    {
        fprintf(stderr, "Unable to create new LP model\n");
        exit(0);
    }
    // constraints in each dimension
    for (int di = 0; di < dimen; di++) {
        set_bounds(lp, di+1, 0.0, 1.0);
    }
}

bool isFeasible(vector<vector<double>> &r1,  vector<vector<double>> &r2, vector<vector<double>> &r1_r2){
    int dim;
    if(r1.empty() || r2.empty()){
        return true;
    }else{
        assert(r1[0].size()==r2[0].size());
        dim=r1[0].size();
    }
    lprec *lp = make_lp(0, dim);
    set_verbose(lp, IMPORTANT);
    set_scaling(lp, SCALE_GEOMETRIC + SCALE_EQUILIBRATE + SCALE_INTEGERS);
    set_add_rowmode(lp, TRUE);
    lpModel(lp, dim);
    vector<double *> store;
    for (vector<double> &r1i:r1) {
        double *tmp=new double[dim+1];
        for (int i = 0; i <dim ; ++i) {
            tmp[i+1]=r1i[i];
        }
        store.push_back(tmp);
        add_constraint(lp, tmp, LE, 0.0);
    }
    for (vector<double> &r2i:r2) {
        double *tmp=new double[dim+1];
        for (int i = 0; i <dim ; ++i) {
            tmp[i+1]=r2i[i];
        }
        store.push_back(tmp);
        add_constraint(lp, tmp, LE, 0.0);
    }
    set_add_rowmode(lp, FALSE);
    set_timeout(lp, 1);
    int ret = solve(lp);
    if(ret<=1){
        // TODO there may be ways to simplify the halfspace
        vector<int> simplify(r1.size()+r2.size());
        for (int i = 1; i <=r1.size()+r2.size(); ++i) {
            simplify[i-1]=i-1;
        }
        for (int idx: simplify) {
            if(idx<r1.size()){
                r1_r2.push_back(r1[idx]);
            }else{
                r1_r2.push_back(r2[idx-r1.size()]);
            }
        }
    }
    delete_lp(lp);
    for(double *tmp: store){
        delete [] (tmp);
    }
    return ret<=1;
}


double region_isFeasible(const vector<int> &order_vals_greater, const vector<int> &unordered_vals_less, float **PG, vector<float> &obj, bool maximize){
    int dim=obj.size();
    if(order_vals_greater.empty() || unordered_vals_less.empty()){
        return true;
    }
    lprec *lp = make_lp(0, dim);
    set_verbose(lp, IMPORTANT);
    set_scaling(lp, SCALE_GEOMETRIC + SCALE_EQUILIBRATE + SCALE_INTEGERS);
    double *tmp_obj=new double[obj.size()+1];
    for (int i = 0; i < obj.size(); ++i) {
        tmp_obj[i+1]=obj[i];
    }
    set_obj_fn(lp, tmp_obj);
    if(maximize){
        set_maxim(lp);
    }else{
        set_minim(lp);
    }
    set_add_rowmode(lp, TRUE);
    lpModel(lp, dim);
    double *tmpa=new double[(order_vals_greater.size()+unordered_vals_less.size()-1+1)*(dim+1)];
    int cnt=0;
    for(int i=0;i<order_vals_greater.size()-1; ++i){
//        vector<double> tmp(dim+1);
        for (int k = 0; k <dim ; ++k) {
            tmpa[cnt*(dim+1)+k+1]=PG[order_vals_greater[i]][k]-PG[order_vals_greater[i+1]][k];
        }
//        tmpa[cnt].emplace_back(tmp);
        add_constraint(lp, &tmpa[cnt*(dim+1)], GE, 0);
        cnt++;
    }
    int last=order_vals_greater.back();
    for (int i: unordered_vals_less) {
        if(i!=last){
//            vector<double> tmp(dim+1);
            for (int k = 0; k <dim ; ++k) {
                tmpa[cnt*(dim+1)+(k+1)]=PG[last][k]-PG[i][k];
            }
//            tmpa.emplace_back(tmp);
            add_constraint(lp, &tmpa[cnt*(dim+1)], GE, 0);
            cnt++;
        }
    }
    for (int k = 0; k <dim ; ++k) {
        tmpa[cnt*(dim+1)+(k+1)]=1;
    }
    add_constraint(lp, &tmpa[cnt*(dim+1)], EQ, 1);
    cnt++;
    set_add_rowmode(lp, FALSE);
    set_timeout(lp, 1);

    int ret = solve(lp);
    double objective;
    if(ret<=1 || ret==7){
        objective=get_objective(lp);
//        REAL *pv=new REAL[1+cnt+dim];
//        get_primal_solution(lp, pv);
//        cout<<"solution:";
//        for (int i = 1+cnt; i < 1+cnt+dim; ++i) {
//            cout<<pv[i]<<",";
//        }
//        cout<<"\n";
//        delete [] (pv);
    }else{
        objective=INFINITY;
    }
    delete_lp(lp);
    delete [](tmp_obj);
    delete [] (tmpa);
    return objective;
}

double main_diagonal(const vector<int> &order_vals_greater, const vector<int> &unordered_vals_less, float **PG, int dim, vector<double> &center_mbb_ret){
    double ret=0;
    vector<float> objv(dim);
    vector<float> debug(dim*2);
    for (int i = 0; i < dim; ++i) {
        objv[i]=1;
        double minv=region_isFeasible(order_vals_greater, unordered_vals_less, PG, objv, false);
        if(minv==INFINITY){
            return INFINITY;
        }
        double maxv=region_isFeasible(order_vals_greater, unordered_vals_less, PG, objv, true);
        if(maxv==INFINITY){
            return INFINITY;
        }
        ret+=maxv-minv; // L1-norm
        center_mbb_ret[i]=(maxv+minv)/2;
        objv[i]=0;
        debug[i*2]=minv;
        debug[i*2+1]=maxv;
    }
//    for (int j:order_vals_greater) {
//        cout<<j<<",";
//    }
//    cout<<"\n";
//    for (float j:debug) {
//        cout<<j<<",";
//    }
//    cout<<"\n";
    return ret;
}