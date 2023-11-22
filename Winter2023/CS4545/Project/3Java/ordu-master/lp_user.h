
#ifndef IPREF_LP_USER_H
#define IPREF_LP_USER_H
#include <vector>
#include <lp_types.h>

using namespace std;

void lpModel(lprec* lp, int& dimen);
bool isFeasible(vector<vector<double>> &r1,  vector<vector<double>> &r2, vector<vector<double>> &r1_r2);
double main_diagonal(const vector<int> &order_vals_greater, const vector<int> &unordered_vals_less, float **PG, int dim, vector<double> &center_mbb_ret);

#endif //IPREF_LP_USER_H
