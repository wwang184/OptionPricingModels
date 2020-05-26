//
// Created by Wanqi Wang on 2019-12-09.
//

#include "defparameter.h"

double alpha = 0.02456; // Mean reversion speed
double mu = 0.0648; // Reversion level
double sigma = 0.0289; //Diffusion
double lambda = -0.2718; // Market price of risk
double rt = 0.06; //test interest rate
double ct = 0.01; //test coupon rate

double S0 = 50;
double K = 50;
double r_simu = 0.10;
double sigma_simu = 0.4;
double time_simu = 0.4167;

double rho_simu = 0.5;
double S1_simu = 50;
double S2_simu = 50;
double sigma2_simu = 0.2;

double S_bs = 100.0;
double sigma_bs = 0.3;
double K_bs = 98;
double r_bs = 0;
double T_bs = 1;
double t_bs = 0.75; //make T-t = 0.25