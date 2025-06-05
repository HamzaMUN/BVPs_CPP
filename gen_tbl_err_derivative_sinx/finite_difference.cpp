#include <cmath>
#include "finite_difference.h"

using namespace std;

// Functions to compute finite difference approximations

double forward_diff(double x, double h)
{
    // D + u(x̄)
    return (sin(x + h) - sin(x)) / h;
}

double backward_diff(double x, double h)
{
    // D - u(x̄)
    return (sin(x) - sin(x - h)) / h;
}

double central_diff(double x, double h)
{
    // Dₒu(x̄)
    return (sin(x + h) - sin(x - h)) / (2 * h);
}

double extrapolated_central_diff(double x, double h)
{
    // D₃u(x̄)
    return (2 * sin(x + h) + 3 * sin(x) - 6 * sin(x - h) + sin(x - 2 * h)) / (6 * h);
}

double compute_error(double approximation, double actual)
{
    // Compute the error by taking the difference between approximation and actual
    return approximation - actual;
}
