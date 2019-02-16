#pragma once

#include <vector>
#include <cmath>


class SimpleStateEstimation{

public:

  // Functions related to state estimation

  // Separation of Concerns:
  // SimpleStateEstimation has nothing do to with deriving & evaluating a polynomial. We only want to use it.
  // -> Separate this functionality from SimpleStateEstimation and put it into Polynomial.h


  double poly_derivative_at (double x_coord, std::vector<double> coeff_arr);

};


// This function does two things:
// 1. Calculate the derivative
// 2. Evaluate the derivative at a point

double SimpleStateEstimation::poly_derivative_at (double x_coord, std::vector<double> coeff_arr){
  double y = 0;
  double diff_coeff;
  for(int i = 0; i < coeff_arr.size(); i++){ // This bug actually happend
    diff_coeff = coeff_arr[i + 1] * (i + 1);
    y += diff_coeff * std::pow(x_coord, i);
  }
  return y;
}
