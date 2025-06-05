#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "../uniformly_spaced_points/uniformly_spaced_points.h"
#include "finite_difference.h"

using namespace std;

int main()
{
    cout << "***\nUsing Finite Difference Methods to approximate:\n1. Forward difference D + u(x̄),\n2. Backward difference D - u(x̄),\n3. Central difference Dₒu(x̄), and\n4. Extrapolated central difference D₃u(x̄).\n***";

    try
    {
        double x = 1.0; // Point of differenciation given in the problem statement
        double actual_derivative = cos(x); // Actual value of the derivative of sin(x)
        vector<double> h_values = {1e-1, 5e-2, 1e-2, 5e-3, 1e-3}; // Given values of h to approximate

        // Print the table header
        cout << "\n***\nThe table showing approximation vs. actual for different finite difference methods at given values of h:\n***\n";
        cout << "h\t\tD + u(x̄)\t\tD - u(x̄)\t\tDₒu(x̄)\t\tD₃u(x̄)\n";
        cout << string(90, '-') << "\n";

        // Computer and print the results
        for(double h: h_values)
        {
            double forward_approx = forward_diff(x, h);
            double backward_approx = backward_diff(x, h);
            double central_approx = central_diff(x, h);
            double extrapolated_central_approx = extrapolated_central_diff(x, h);

            cout << scientific << setprecision(4) << h << "\t"
            << compute_error(forward_approx, actual_derivative) << "\t\t"
            << compute_error(backward_approx, actual_derivative) << "\t\t"
            << compute_error(central_approx, actual_derivative) << "\t"
            << compute_error(extrapolated_central_approx, actual_derivative) << "\n";
        }


    } catch(const exception& e)
    {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}
