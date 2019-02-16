#pragma once

#include <vector>
#include <cmath>


class SimpleStateEstimation{

public:

  // Functions related to state estimation


  double poly_derivative_at (double x_coord, std::vector<double> coeff_arr);

};




double SimpleStateEstimation::poly_derivative_at (double x_coord, std::vector<double> coeff_arr){
  double y = 0;
  double diff_coeff;
  for(int i = 0; i < coeff_arr.size() - 1; i++){
    diff_coeff = coeff_arr.at(i + 1) * (i + 1);
    y += diff_coeff * std::pow(x_coord, i);
  }

  return y;
}
