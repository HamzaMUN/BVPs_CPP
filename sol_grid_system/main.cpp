#include <iostream>
#include <vector>
#include <cmath>
#include "bvp_solver.h"
#include "error_calculator.h"

using namespace std;

int main()
{
    cout << "***\nUsing Finite Difference Methods to solve the BVP and compute errors.\n***\n";

    // Define N values
    vector<int> N_values = {10, 20, 40, 80, 160};
    vector<double> errors;

    // Solve BVP using bvp_solver.h and calculating errors using error_calculator.h
    for(int N : N_values)
    {
        vector<double> x(N + 2), u(N + 2); // Define vectors to store results including boundary values (i.e., N + 2)

        // Solve the BVP using bvp_solver.h
        solve_bvp(N, x, u);

        // Compute the maximum error between approximations and exact solution using error_calculator.h
        double max_error = compute_max_error(x, u);
        errors.push_back(max_error);

        // Print the max error for the current iteration of N
        cout << "N = " << N << ", Max Error = " << max_error << "\n";
    }

    // Compute the error ratios between consecutive N values
    cout << "\nError Ratios (should approach 4):\n";
    for(size_t i = 1; i < errors.size(); i++)
    {
        double ratio = errors[i - 1] / errors[i];
        cout << "N = " << N_values[i] << "/" << N_values[i - 1] << ": " << ratio << "\n";
    }


    return 0;
}
