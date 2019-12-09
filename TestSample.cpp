//
// Created by Wanqi Wang on 2019-12-09.
//

#include <iostream>
#include <cmath>
#include <vector>
#include "normdist.h"
#include "defparameter.h"
#include "cdflib.h"

#include "CIRModel.h"
#include "VasicekModel.h"

using namespace std;


int main() {
    cout << "Zero Coupon Bond Under CIR: " << endl;
    for (int i = 0; i < 30; i++) {
        cout << zeroCouponBondUnderCIR(-1, i) << endl;
    }
    cout << "*******************************"<< endl;
    cout << "Zero Coupon Bond Under Vasicek: " << endl;
    for (int i = 0; i < 30; i++) {
        cout << zeroCouponBondPriceUnderVasicek(-1, i) << endl;
    }

}
