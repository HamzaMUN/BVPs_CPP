#include "rhs_vector.h"
#include "bvp_functions.h"
#include <cmath>

std::vector<double> gen_rhs_vector(int N, const std::vector<double>& main_diag, const std::vector<double>& sup_diag, const std::vector<double>& sub_diag, const std::function<double(double)>& f, const std::function<double()>& A, const std::function<double()>& B)
{
    std::vector<double> grid_points(N);
    double A_val = A();
    double B_val = B();
    double h = (B_val - A_val) / (N + 1);

    // Generate grid points
    for(int i = 0; i < N; i++)
    {
        grid_points[i] = (i + 1) * h;
    }

    // Generate right-hand side vector
    std::vector<double> F(N);

    for(int i = 0; i < N; i++)
    {
        F[i] = f(grid_points[i]);
    }

    // Adjust for boundary conditions
    F[0] = -(A_val / (h * h)); // Boundary at u(0) = A = 0
    F[N - 1] = -(B_val / (h * h)); // Boundary at u(1) = B = 1

    return F;
}
