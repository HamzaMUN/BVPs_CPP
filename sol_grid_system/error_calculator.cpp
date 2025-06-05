#include <cmath>
#include "error_calculator.h"
#include "../gen_tridiagonal_matrix_and_rhs_vector/bvp_functions.h"

double compute_max_error(const std::vector<double>& x, const std::vector<double>& u)
{
    double max_error = 0.0;

    for(size_t i = 0; i < x.size(); i++)
    {
        double exact_solution_val = exact_solution(x[i]);
        max_error = std::max(max_error, std::abs(exact_solution_val - u[i]));
    }

    return max_error;
}
