
#include <iostream>
#include <cmath>
#include <normdist.h>
using namespace std;

double callOptionPriceWithDividends(double S, // Spot price
                                    double t, // Current time
                                    double K, // Strike price
                                    double r, // Interest rate (constant)
                                    double d, // Dividend yield
                                    double sigma, //Volatility
                                    double T // Maturity time
){
    double d1 = (log(S/K) + (r - d + sigma * sigma/2.)*(T-t)) / (sigma * sqrt(T-t));
    double d2 = (log(S/K) + (r - d - sigma * sigma/2.)*(T-t)) / (sigma * sqrt(T-t));
    return S * exp(-d*(T-t))* N(d1) - K * exp(-r*(T-t)) * N(d2);
}

double callOptionPrice(double S, // Spot price
                       double t, // Current time
                       double K, // Strike price
                       double r, // Interest rate (constant)
                       double sigma, //Volatility
                       double T // Maturity time
){
    double d1 = (log(S/K) + (r  + sigma * sigma/2.)*(T-t)) / (sigma * sqrt(T-t));
    double d2 = (log(S/K) + (r  - sigma * sigma/2.)*(T-t)) / (sigma * sqrt(T-t));
    return S * N(d1) - K * exp(-r*(T-t)) * N(d2);
}

void optionPricePartials(const double& S,
                         const double& K,
                         const double& r,
                         const double& sigma,
                         const double& T,
                         const double& t,
                         double& Delta,
                         double& Gamma,
                         double& Theta)
        //double& Vega,
        //double& Rho)
{
    double d1 = (log(S/K) + (r + sigma * sigma/2.)*(T-t)) / (sigma * sqrt(T-t));
    double d2 = (log(S/K) + (r - sigma * sigma/2.)*(T-t)) / (sigma * sqrt(T-t));
    Delta = N(d1);
    Gamma = n(d1)/(S*sqrt(T-t));
    Theta = -(S*sigma*n(d1))/(2*sqrt(T-t)) - r*K*exp(-r*(T-t))*N(d2);

}
double optionExpectedReturn(const double& C,
                            const double& S,
                            const double& sigma,
                            const double& mu,
                            const double& Delta,
                            const double& Gamma,
                            const double& Theta){
    return (sigma*sigma*S*S*Gamma/2 + mu*S*Delta + Theta)/C;

}

double optionVolatility(const double& S,
                        const double& C,
                        const double& sigma,
                        const double& delta){
    return S/C*sigma*delta;
}