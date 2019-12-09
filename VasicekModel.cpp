#include <iostream>
#include <cmath>
#include <vector>
#include "normdist.h"
using namespace std;

//Vasicek model is one of the one-factor models for interest rates.
//It assumes a Gaussian, mean reverting process for the instantaneous short rate:
// dr = alpha (mu - r) dt + sigma dW (under P-measure)
//It can also be expressed in Q-measure (risk neutral measure) and forward measure

//Question: We need Q measure because under Q-measure the discounted option value is a martingale.
//What about forward measure?


static double alpha = 0.02456; // Mean reversion speed
static double mu = 0.0648; // Reversion level
static double sigma = 0.0289; //Diffusion
static double lambda = -0.2718; // Market price of risk
static double rt = 0.06; //test interest rate
static double ct = 0.01; //test coupon rate


//In Vasicek model, alpha^ = alpha, and mu^ = mu + sigma*lambda/alpha
//In CIR model, alpha^ = alpha + lambda, and mu^ = alpha*mu/(alpha+lambda)


double F(int t, int T){
    return (1 - exp(- alpha * (T-t))) / alpha;
}

double G(int t, int T){
    return (mu - pow(sigma,2) / (2*pow(alpha,2)) - sigma*lambda/alpha) * (T - t - F(t,T)) + pow(sigma,2) * pow(F(t,T),2) / (4*alpha);

}
double zeroCouponBondPriceUnderVasicek(int t, int T){
    return exp(-rt*F(t,T)-G(t,T));

}

double zeroCouponBondOptionPriceUnderVasicek(int t,
                                             int T, //Option expiration date
                                             int s, // Bond expiration date)
                                             double K){ // Strike price
    //Similar to original B-S under assumption of constant interest rate.
    //That's because P(T,s), which is underlying asset price, is lognormal distributed just like original B-S.

    double ps = zeroCouponBondPriceUnderVasicek(t, s);
    double pt = zeroCouponBondPriceUnderVasicek(t, T);
    double vp = (1 - exp(-2*alpha*(T-t))) / (2*alpha) * pow(sigma,2) * pow(F(T,s),2);
    double mp = log(ps/pt) - vp/2;
    double mp2 = mp + vp;
    double d1 = (mp2-log(K))/sqrt(vp);
    double d2 = (mp-log(K)/sqrt(vp));
    return ps * N(d1) - pt * K * N(d2);
}

double zeroCouponBondFuturesUnderVasicek(int t,
                             int T, // Future settlement time
                             int s){ // Bond expiration time
    double X = F(t,s) - F(t,T);
    double Y = (mu - sigma*lambda/alpha - pow(sigma,2)/(2*pow(alpha,2)) * (s - T - X)) - pow(sigma,2)/(2*pow(alpha,2) * (X-alpha*X/2-F(T,s)));

    return exp(rt*X-Y);
}

double zeroCouponBondFuturesOptionUnderVasicek(int t,
                                    int T,  // Option expiration
                                    int s,  // Futures settlement time
                                    int w,
                                    double K){ // Bond expiration time
    double p = zeroCouponBondPriceUnderVasicek(t, T);
    double phi = zeroCouponBondFuturesUnderVasicek(t,s,w);
    double X = F(T,w) - F(T,s);
    double H = p * phi * exp(pow(sigma,2))/2*pow(F(t,T),2)*X;
    double Vh = pow(X,2) * pow(sigma,2) * (1-exp(-2*alpha*(T-t))) / (2*alpha);
    double dh = (log(H/(p*K)) + Vh/2)/sqrt(Vh);
    return H * N(dh) - p*K*N(dh-sqrt(Vh));
}

double couponBondUnderVasicek(int t, vector<int> T){
    double B = 0;
    double n = T.size();
    for (int i = 0; i < n-1; i++){
        B += ct* zeroCouponBondPriceUnderVasicek(t,T[i]);
    }
    B += zeroCouponBondPriceUnderVasicek(t,T[n-1]);
    return B;
}

double couponBondFuturesUnderVasicek(int t, int Tf, vector<int> T){
    double F = 0;
    double n = T.size();
    for (int i = 0; i < n-1; i++){
        F += ct* zeroCouponBondFuturesUnderVasicek(t, Tf, T[i]);
    }
    F += zeroCouponBondFuturesUnderVasicek(t, Tf, T[n-1]);
    return F;
}

double couponBondOptionsUnderVasicek(int t, int Tc, vector<int> T, vector<double> ci, double K){
    double C = 0;
    double n = T.size();
    for (int i = 0; i < n; i++){
        C += ci[i] * zeroCouponBondOptionPriceUnderVasicek(t, Tc, T[i], K);
    }
    return C;
}

int main(){
    for(int i = 0; i < 30; i++)
        cout << zeroCouponBondPriceUnderVasicek(-1, i) <<endl;

    cout << zeroCouponBondOptionPriceUnderVasicek(1,2,30,30);

}