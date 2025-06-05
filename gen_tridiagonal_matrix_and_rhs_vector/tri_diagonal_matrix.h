#ifndef TRI_DIAGONAL_MATRIX_H_INCLUDED
#define TRI_DIAGONAL_MATRIX_H_INCLUDED

#include <vector>
#include <functional>

// Function to generate a tridiagonal matrix where N is the total number of interior points.
void gen_tridiagonal_matrix(int N, std::vector<double>& main_diag, std::vector<double>& sup_diag, std::vector<double>& sub_diag, const std::function<double()>& A, const std::function<double()>& B);

#endif // TRI_DIAGONAL_MATRIX_H_INCLUDED
