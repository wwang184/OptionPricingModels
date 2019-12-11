cmake_minimum_required(VERSION 3.14)
project(OptionPricingModels)

set(CMAKE_CXX_STANDARD 14)

include_directories(./headers)
include_directories(./tools)


add_executable(OptionPricingModels VasicekModel.cpp tools/normdist.cpp BlackScholesModel.cpp CIRModel.cpp defparameter.cpp tools/cdflib.cpp TestSample.cpp NumericalMethods/simulation.cpp headers/simulation.h)