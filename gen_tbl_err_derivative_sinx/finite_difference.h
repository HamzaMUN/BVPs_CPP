#ifndef FINITE_DIFFERENCE_H_INCLUDED
#define FINITE_DIFFERENCE_H_INCLUDED

// Forward difference D + u(x̄)
double forward_diff(double x, double h);

// Backward difference D - u(x̄)
double backward_diff(double x, double h);

// Central difference Dₒu(x̄)
double central_diff(double x, double h);

// Extrapolated central difference D₃u(x̄)
double extrapolated_central_diff(double x, double h);

// Function to compute error
double compute_error(double approximation, double actual);

#endif // FINITE_DIFFERENCE_H_INCLUDED
