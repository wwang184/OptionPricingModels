//
// Created by Wanqi Wang on 2019-12-08.
//
#include <cmath>
#include <iostream>
#include "normdist.h"
using namespace std;

#ifndef PI
const double PI = 3.141592653589793238462643;
#endif

//An approximation of cumulative normal distribution function
double N(double z){
    if (z > 6.0) return 1.0;
    if (z < -6.0) return 0.0;

    double b1 = 0.31938153;
    double b2 = -0.356563782;
    double b3 = 1.781477937;
    double b4 = -1.821255978;
    double b5 = 1.330274429;
    double p = 0.2316419;
    double c2 = 0.3989423;

    double a = fabs(z);
    double t = 1.0/(1.0+a*p);
    double b = c2*exp((-z)*(z/2.0));
    double n = ((((b5*t+b4)*t+b3)*t+b2)*t+b1)*t;
    n = 1.0-b*n;
    if (z < 0.0) n = 1.0 -n;
    return n;
};
