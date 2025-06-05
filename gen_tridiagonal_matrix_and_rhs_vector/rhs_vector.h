#ifndef RHS_VECTOR_H_INCLUDED
#define RHS_VECTOR_H_INCLUDED

#include <vector>
#include <functional>

// Function to generate the Right-hand side vector to solve a system of linear equations where N is the total number of interior points.
std::vector<double> gen_rhs_vector(int N, const std::vector<double>& main_diag, const std::vector<double>& sup_diag, const std::vector<double>& sub_diag, const std::function<double(double)>& f, const std::function<double()>& A, const std::function<double()>& B);

#endif // RHS_VECTOR_H_INCLUDED
