#include <cmath>
#include "bvp_functions.h"

// Define example: Functions to solve the linear system

double A()
{
    return 0.0; // Constant function u(0) = A = 0
}

double B()
{
    return 1.0; // Constant function u(1) = B = 1
}

double f(double x)
{
    return 2.0 * x; // Linear function f(x) = 2x
}

double exact_solution(double x)
{
    return ((x * x * x) + (2 * x)) / 3; // Exact solution for f(x) = 2x at u(0) = 0 and u(1) = 1
}
