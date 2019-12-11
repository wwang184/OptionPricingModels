//
// Created by Wanqi Wang on 2019-12-10.
//

#include "simulation.h"
#include <cmath>
#include "normdist.h"
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

double MC_simulate_option_price(double S, //Spot price
        double K, //Strike Price
        double r, //Interest rate
        double sigma, //Constant volatility
        double time, //Time to maturity
        double N){
    static mt19937 rng;
    normal_distribution<> ND(0.,1.);
    //ND(rng);
    double sum = 0.;
    for(int i = 0;i < N; i++)
    {
        double phi = ND(rng);
        double ST = S * exp( (r- 0.5 * pow(sigma,2)) * time + phi * sigma * sqrt(time));
        sum += max(ST - K,0.);
    }
    return sum * exp(-r * time) / N;

}

double MC_simulate_exchange_option_price(double S1,
                                      double S2,
                                      double rho,
                                      double r,
                                      double sigma1,
                                      double sigma2,
                                      double time,
                                      double N){
    static mt19937 rng(1);
    static mt19937 rng2(2);
    normal_distribution<> ND(0.,1.);
    //ND(rng);
    double sum = .0;
    for(int i = 0;i < N; i++)
    {
        double phi = ND(rng);
        double phi2 = ND(rng2);
        double ST1 = S1 * exp( (r- 0.5 * pow(sigma1,2)) * time + phi * sigma1 * sqrt(time) * sqrt(1-pow(rho,2)) + phi2 * sigma2 * rho * sqrt(time) );
        double ST2 = S2 *exp( (r- 0.5 * pow(sigma2,2)) * time + phi2 * sigma2 * rho* sqrt(time));
        sum += max(ST1 - ST2,0.);
    }
    return sum * exp(-r * time) / N;
}
