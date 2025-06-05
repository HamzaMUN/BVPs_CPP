#include <cmath>
#include <vector>
#include <functional>
#include "bvp_solver.h"
#include "tridiagonal_solver.h"
#include "../uniformly_spaced_points/uniformly_spaced_points.h"
#include "../gen_tridiagonal_matrix_and_rhs_vector/bvp_functions.h"
#include "../gen_tridiagonal_matrix_and_rhs_vector/tri_diagonal_matrix.h"
#include"../gen_tridiagonal_matrix_and_rhs_vector/rhs_vector.h"

//Function to solve the boundary value problem (BVP)
void solve_bvp(int N, std::vector<double>& x, std::vector<double>& u)
{
    // Define the linear system: Use the functions from bvp_functions.h
    std::function<double()> A_func = &A;
    std::function<double()> B_func = &B;
    std::function<double(double)> f_func = &f;

    // Generate uniformly spaced grid points using uniformly_spaced_points.h
    x = gen_uniform_points(A_func(), B_func(), N);

    // Generate the matrix diagonals using tri_diagonal_matrix.h
    std::vector<double> main_diag(N), sup_diag(N), sub_diag(N);
    gen_tridiagonal_matrix(N, main_diag, sup_diag, sub_diag, A_func, B_func);

    // Generate the right-hand side vector using rhs_vector.h
    std::vector<double> rhs_vector = gen_rhs_vector(N, main_diag, sup_diag, sub_diag, f_func, A_func, B_func);

    // Solve the tridiagonal system using the Thomas algorithm using tridiagonal_solver.h
    std::vector<double> u_interior = solve_tridiagonal_system(N, main_diag, sup_diag, sub_diag, rhs_vector);
    for(int i = 0; i < N; i++)
    {
        u[i + 1] = u_interior[i];
    }
    // Apply boundary conditions
    u[0] = A_func();
    u[N + 1] = B_func();
}
