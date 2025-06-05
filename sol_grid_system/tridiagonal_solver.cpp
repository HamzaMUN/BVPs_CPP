#include <cmath>
#include <vector>
#include "tridiagonal_solver.h"

std::vector<double> solve_tridiagonal_system(int N, const std::vector<double>& main_diag, const std::vector<double>& sup_diag, const std::vector<double>& sub_diag, const std::vector<double>& rhs)
{
    std::vector<double> u(N);
    std::vector<double> c_prime(N);
    std::vector<double> d_prime(N);

    //Forward sweep to modify the coefficients
    c_prime[0] = sup_diag[0] / main_diag[0];
    d_prime[0] = rhs[0] / main_diag[0];

    for(int i = 1; i < N; i++)
    {
        double m = main_diag[i] - sub_diag[i] * c_prime[i - 1];
        c_prime[i] = sup_diag[i] / m;
        d_prime[i] = (rhs[i] - sub_diag[i] * d_prime[i - 1]) / m;
    }

    // Back substitution
    u[N - 1] = d_prime[N - 1];
    for(int i = N - 2; i >= 0; i--)
    {
        u[i] = d_prime[i] - c_prime[i] * u[i + 1];
    }

    return u;
}
