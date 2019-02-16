#pragma once

#include <vector>
class Polynomial{

public:
  Polynomial(std::vector<double> coefficients) :
   _coefficients(coefficients)
  {}

  Polynomial() :
          _coefficients()
  {}

  std::vector<double> const &
  GetCoefficients() const
  {
    return _coefficients;
  }


  double evaluateAt(double x_coord)
  {
    double power = 1.0;
    double result = 0.0;
    for(auto const & coeff : _coefficients)
    {
        result += power * coeff;
        power *= x_coord;
    }
    return result;
  }

  Polynomial CalculateDerivative() const
  {
    if( _coefficients.size() - 1< 0)
    {
      return Polynomial();
    }

    std::vector<double> derived_coefficients;
    for(int i = 0; i < _coefficients.size() - 1; ++i)
    {
      derived_coefficients.push_back(_coefficients.at(i+1) *(i+1));
    }
    return Polynomial(derived_coefficients);
  }

  void Print()
  {
    for(auto const & coeff : _coefficients)
    {
      std::cout << coeff << " " ;
    }
    std::cout << std::endl;
  }


private:

  std::vector<double> _coefficients;

};



