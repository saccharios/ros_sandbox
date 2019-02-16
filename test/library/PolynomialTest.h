#pragma once

#include <gtest/gtest.h>
#include <iostream>
#include "SimpleStateEstimation.h"
#include "Polynomial.h"
#include <algorithm>


void PrintResult(double x_coord, std::vector<double> const & coeff_arr, double result)
{

    std::cout << "-------------------------------------\n";
    std::cout << "The input polynomial is ";
    for(auto const & e : coeff_arr){
        std::cout << e << " ";
    }
    std::cout << std::endl;
    std::cout << "The derivative at point " << x_coord << " is " << result;
    std::cout << std::endl;
    std::cout << "-------------------------------------\n";

}



void run(double x_coord, std::vector<double> const & coeff_arr)
{
    SimpleStateEstimation simpleStateEstimation;
    double result = simpleStateEstimation.poly_derivative_at(x_coord, coeff_arr);


    PrintResult(x_coord, coeff_arr, result);
}

void run_2(double x_coord, std::vector<double> const & coeff_arr)
{
    Polynomial polynomial(coeff_arr);

    Polynomial derived_polynomial = polynomial.CalculateDerivative();


    std::cout << derived_polynomial;

    double result = derived_polynomial.evaluateAt(x_coord);

    PrintResult(x_coord, coeff_arr, result);

}



TEST(RunComparison, compare){
    double x_coord = 3.0;
    std::vector<double> coeff_arr={1.0, 0.3, 0.7, 0.8};

    run(x_coord, coeff_arr);


    run_2(x_coord, coeff_arr);
}


