#include <iostream>
#include <cmath>
#include "normdist.h"
#include "defparameter.h"
#include "cdflib.h"

using namespace std;

double A(int t, int T){
    double gma = sqrt(pow((alpha+lambda),2) + 2*pow(sigma,2));
    double dom = 2 * gma * exp((alpha+lambda+gma)*(T-t)/2) / ((alpha+lambda+gma) * exp(gma*(T-t)-1) + 2*gma);
    return pow(dom, 2*alpha*mu/pow(sigma,2));
}

double B(int t, int T){
    double gma = sqrt(pow((alpha+lambda),2) + 2*pow(sigma,2));
    return 2 * (exp(gma *(T-t)) - 1) / ((alpha+lambda+gma) * exp(gma*(T-t)-1) + 2*gma);

}

double zeroCouponBondUnderCIR(int t, int T){
    return A(t,T) * exp(-rt*B(t,T));
}

double zeroCouponBondOptionUnderCIR(int t, int T, int s, double K){
    double gma = sqrt(pow((alpha+lambda),2) + 2*pow(sigma,2));
    double phi = 2 * gma / (pow(sigma,2)*(exp(gma*(T-t))-1));
    double shi = (alpha + lambda + gma) /pow(sigma,2);
    double r_star = log(A(T,s)/K)/B(T,s);
    double x1 = 2 * (phi + shi + B(T, s)) * r_star;
    double x2 = 2*(phi+shi)*r_star;
    double df = 4*alpha*mu/pow(sigma,2);
    double nc1 = 2*pow(phi,2)*exp(gma*(T-t)*rt)/(phi+shi+B(T,s));
    double nc2 = 2*pow(phi,2)*exp(gma*(T-t)*rt)/(phi+shi);
    double cdf1 = 0;
    double cdf2 = 0;
    int data = 0;
    chi_noncentral_cdf_values(&data, &x1, &nc1, reinterpret_cast<int *>(&df), &cdf1 );
    chi_noncentral_cdf_values(&data, &x2, &nc2, reinterpret_cast<int *>(&df), &cdf2 );
    return zeroCouponBondUnderCIR(t,s)*cdf1 - zeroCouponBondUnderCIR(t,T)*K*cdf2;
}
