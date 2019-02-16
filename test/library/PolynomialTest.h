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


// I want to calculate the derivative of a polynomial at a certain point.

void run(double x_coord, std::vector<double> const & coeff_arr)
{
    // Needs an instance of SimpleStateEstimation
    SimpleStateEstimation simpleStateEstimation;
    double result = simpleStateEstimation.poly_derivative_at(x_coord, coeff_arr);

    PrintResult(x_coord, coeff_arr, result);
}

void run_2(double x_coord, std::vector<double> const & coeff_arr)
{
    Polynomial polynomial(coeff_arr);
    Polynomial derived_polynomial = polynomial.CalculateDerivative(); // derived_polynomial be stored and reused later, or can even be stored inside the class Polynomial
    double result = derived_polynomial.evaluateAt(x_coord);

    PrintResult(x_coord, coeff_arr, result);
}



TEST(RunComparison, compare){
    double x_coord = 3.0;
    std::vector<double> coeff_arr={1.0, 0.3, 0.7, 0.8};

    run(x_coord, coeff_arr);

    run_2(x_coord, coeff_arr);
}




//
//TEST(Polynomial, CalculateDerivative)
//{
//    std::vector<double> coeff_arr={1.0, 0.3, 0.7, 0.8};
//
//    Polynomial polynomial(coeff_arr);
//    Polynomial derived_polynomial = polynomial.CalculateDerivative();
//
//    EXPECT_EQ(derived_polynomial.GetDegree(), polynomial.GetDegree() -1);
//    std::stringstream stream;
//    stream << derived_polynomial;
//    EXPECT_EQ(std::string() +"0.3 1.4 2.4 ", stream.str());
//}
//
//TEST(Polynomial, EvaluateAt)
//{
//    std::vector<double> coeff_arr={1.0, 0.3, 0.7, 0.8};
//
//    Polynomial polynomial(coeff_arr);
//    double x = 3.7;
//    double expected = coeff_arr.at(0) + coeff_arr.at(1)*x + coeff_arr.at(2)*x*x + coeff_arr.at(3) *x*x*x;
//
//
//    double result = polynomial.evaluateAt(x);
//    EXPECT_DOUBLE_EQ(result,expected);
//}

// If you look at the Polynomial class, what tests are missing?