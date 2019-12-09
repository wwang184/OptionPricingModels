cmake_minimum_required(VERSION 3.14)
project(OptionPricingModels)

set(CMAKE_CXX_STANDARD 14)

add_executable(OptionPricingModels VasicekModel.cpp normdist.h normdist.cpp BlackScholesModel.cpp CIRModel.cpp)