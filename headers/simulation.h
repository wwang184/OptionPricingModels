//
// Created by Wanqi Wang on 2019-12-10.
//

#ifndef OPTIONPRICINGMODELS_SIMULATION_H
#define OPTIONPRICINGMODELS_SIMULATION_H

#endif //OPTIONPRICINGMODELS_SIMULATION_H

double MC_simulate_option_price(double S,
                                double r,
                                double sigma,
                                double time,
                                double K,
                                double N);
double MC_simulate_exchange_option_price(double S1,
                                         double S2,
                                         double rho,
                                         double r,
                                         double sigma1,
                                         double sigma2,
                                         double time,
                                         double N);

