#ifndef OPTIONPRICINGMODELS_VASICEKMODEL_H
#define OPTIONPRICINGMODELS_VASICEKMODEL_H

#endif //OPTIONPRICINGMODELS_VASICEKMODEL_H

#include <vector>
using namespace std;

double F(int t, int T);
double G(int t, int T);
double zeroCouponBondPriceUnderVasicek(int t, int T);
double zeroCouponBondOptionPriceUnderVasicek(int t,
                                             int T, //Option expiration date
                                             int s, // Bond expiration date)
                                             double K);
double zeroCouponBondFuturesUnderVasicek(int t,
                                         int T, // Future settlement time
                                         int s);
double zeroCouponBondFuturesOptionUnderVasicek(int t,
                                               int T,  // Option expiration
                                               int s,  // Futures settlement time
                                               int w,
                                               double K);
double couponBondUnderVasicek(int t, vector<int> T);
double couponBondFuturesUnderVasicek(int t, int Tf, vector<int> T);
double couponBondOptionsUnderVasicek(int t, int Tc, vector<int> T, vector<double> ci, double K);
