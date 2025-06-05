#include "tri_diagonal_matrix.h"
#include "bvp_functions.h"

void gen_tridiagonal_matrix(int N, std::vector<double>& main_diag, std::vector<double>& sup_diag, std::vector<double>& sub_diag, const std::function<double()>& A, const std::function<double()>& B)
{
    double h = 1.0 / (N + 1); // Grid spacing
    double x;

    // Compute diagonals for the tridiagonal matrix
    for(int j = 0; j < N; j++)
    {
        x = (j + 1) * h;
        double A_val = A();
        double B_val = B();

        main_diag[j] = -2 / (h * h);
        if (j > 0)
        {
            sub_diag[j] = 1 / (h * h);
        }
        if (j < N - 1)
        {
            sup_diag[j] = 1 / (h * h);
        }
    }
}
