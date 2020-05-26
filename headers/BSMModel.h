//
// Created by Wanqi Wang on 2019-12-12.
//

#ifndef OPTIONPRICINGMODELS_BLACKSCHOLESPRICINGMODEL_H
#define OPTIONPRICINGMODELS_BLACKSCHOLESPRICINGMODEL_H

#endif //OPTIONPRICINGMODELS_BLACKSCHOLESPRICINGMODEL_H

double callOptionPriceWithDividends(double S, // Spot price
                                    double t, // Current time
                                    double K, // Strike price
                                    double r, // Interest rate (constant)
                                    double d, // Dividend yield
                                    double sigma, //Volatility
                                    double T // Maturity time
);

double callOptionPrice(double S, // Spot price
                       double t, // Current time
                       double K, // Strike price
                       double r, // Interest rate (constant)
                       double sigma, //Volatility
                       double T // Maturity time
);

void optionPricePartials(const double& S,
                         const double& K,
                         const double& r,
                         const double& sigma,
                         const double& T,
                         const double& t,
                         double& Delta,
                         double& Gamma,
                         double& Theta);

double optionExpectedReturn(const double& C,
                            const double& S,
                            const double& sigma,
                            const double& mu,
                            const double& Delta,
                            const double& Gamma,
                            const double& Theta);

double optionVolatility(const double& S,
                        const double& C,
                        const double& sigma,
                        const double& delta);

