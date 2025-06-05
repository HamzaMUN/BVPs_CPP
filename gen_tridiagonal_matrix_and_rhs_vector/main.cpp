#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include "tri_diagonal_matrix.h"
#include "rhs_vector.h"
#include "bvp_functions.h"

using namespace std;

int main()
{
    int N;
    cout << "Enter the number of interior grid points (N): ";
    cin >> N;

    // Defining the linear system: Use the functions from bvp_functions.h
    function<double()> A_func = &A;
    function<double()> B_func = &B;
    function<double(double)> f_func = &f;

    // Vectors to store the diagonals of the tridiagonal matrix
    vector<double> main_diag(N), sup_diag(N), sub_diag(N);

    // Generate the tridiagonal matrix
    gen_tridiagonal_matrix(N, main_diag, sup_diag, sub_diag, A_func, B_func);

    // Generate the Right-hand side vector
    vector<double> rhs_vector = gen_rhs_vector(N, main_diag, sup_diag, sub_diag, f_func, A_func, B_func);

    // Print the tridiagonal matrix
    cout << "\nTridiagonal Matrix (M):\n";
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                // Print the main diagonal
                cout << main_diag[i] << "\t";
            }
            else if(i == j - 1)
            {
                // Print the super diagonal
                cout << sup_diag[i] << "\t";
            }
            else if(i == j + 1)
            {
                // Print the sub diagonal
                cout << sub_diag[i] << "\t";
            }
            else
            {
                // Print 0 for non-diagonal positions
                cout << "0\t";
            }
        }

        cout << "\n";
    }

    // Print the right-hand side vector
    cout << "\nRight-Hand Side Vector (F):\n";
    for(double val : rhs_vector)
    {
        cout << val << " ";
    }

    cout << "\n";

    return 0;
}
