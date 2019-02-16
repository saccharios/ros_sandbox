#pragma once

#include <vector>
class Polynomial{

public:
    Polynomial(std::vector<double> coefficients) :
            _coefficients(coefficients)
    {}

    Polynomial() :
            _coefficients({0})
    {}

    std::vector<double> const &
    GetCoefficients() const
    {
      return _coefficients;
    }


    double evaluateAt(double x_coord) const
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

    unsigned int GetDegree() const
    {
      return _coefficients.size() - 1;
    }

    Polynomial CalculateDerivative() const
    {
      if( GetDegree()  < 1)
      {
        return Polynomial();
      }

      std::vector<double> derived_coefficients;
      for(int i = 0; i < _coefficients.size(); ++i) // The same bug is here
      {
        derived_coefficients.push_back(_coefficients[i+1] *(i+1));
      }
      return Polynomial(derived_coefficients);
    }


    // If needed, this class can be easily extended
    // Polynomial Integrate() {...}
    // std::vector CalculateZeros() {...}
    // bool IsMonotoniouslyIncreasing() {...}

    // Add functionality only if needed, but strive to write code that is easily extended when you need to do it


    // Overload the operator<< for nice printing
    template<typename Stream>
    friend
    Stream & operator << (Stream & stream, Polynomial p)
    {
      for (auto const & coeff : p._coefficients)
      {
        stream << coeff << " ";
      }
      return stream;
    }

private:
    // The internals can be changed later easily. For example, does it have to be a vector? or does std::array do it?
    std::vector<double> _coefficients;

};





