#ifndef ERROR_CALCULATOR_H_INCLUDED
#define ERROR_CALCULATOR_H_INCLUDED

#include <vector>

// Function to compute the maximum error between exact solution and approximation
double compute_max_error(const std::vector<double>& x, const std::vector<double>& u);

#endif // ERROR_CALCULATOR_H_INCLUDED
