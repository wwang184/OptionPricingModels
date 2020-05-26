//
// Created by Wanqi Wang on 2019-12-09.
//

#include <iostream>
#include <cmath>
#include <vector>
#include "normdist.h"
#include "defparameter.h"
#include "cdflib.h"

#include "BSMModel.h"
#include "CIRModel.h"
#include "VasicekModel.h"

#include "simulation.h"

using namespace std;


int main() {

    cout << "Black Scholes Call Option Price: " << endl;
    cout << callOptionPrice(S_bs,t_bs,K_bs,r_bs,sigma_bs,T_bs) <<endl;
    cout << "*******************************"<< endl;

    cout << "Zero Coupon Bond Under CIR: " << endl;
    for (int i = 0; i < 30; i++) {
        cout << zeroCouponBondUnderCIR(-1, i) << endl;
    }

    cout << "*******************************"<< endl;
    cout << "Zero Coupon Bond Under Vasicek: " << endl;
    for (int i = 0; i < 30; i++) {
        cout << zeroCouponBondPriceUnderVasicek(-1, i) << endl;
    }

    cout << "*******************************"<< endl;
    cout << "Simulated Option Price: " << endl;
    cout << MC_simulate_option_price(S0, r_simu, sigma_simu,time_simu,K, 1000) << endl;
    cout << "Simulated Exchenge Option Price: " << endl;
    cout << MC_simulate_exchange_option_price(S1_simu,
                                             S2_simu,
                                             rho_simu,
                                             r_simu,
                                             sigma_simu,
                                             sigma2_simu,
                                             time_simu,
                                             1000) << endl;


}
