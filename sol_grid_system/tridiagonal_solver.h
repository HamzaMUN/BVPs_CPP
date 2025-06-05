#ifndef TRIDIAGONAL_SOLVER_H_INCLUDED
#define TRIDIAGONAL_SOLVER_H_INCLUDED

#include <vector>

// Function to solve a tridiagonal system using the Thomas algorithm
std::vector<double> solve_tridiagonal_system(int N, const std::vector<double>& main_diag, const std::vector<double>& sup_diag, const std::vector<double>& sub_diag, const std::vector<double>& rhs);

#endif // TRIDIAGONAL_SOLVER_H_INCLUDED
