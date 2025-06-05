#include <iostream>
#include <vector>
#include <iomanip>
#include "uniformly_spaced_points.h"

using namespace std;

int main()
{
    cout << "***\nPlease provide the values for the start of the interval (a), end of the interval (b) and number of interior points (N) to generate a list of uniformly spaced points.\n***";

    int a, b, N;

    try
    {
        // Get user input
        get_user_input(a, b, N);

        // Validate input
        validate_input(a, b, N);

        // Generate unifromly spaced points
        vector<double> points = gen_uniform_points(a, b, N);

        // Print the result
        cout << "***\nOutput\n***\nThe uniformly spaced points are:\n";

        for(double point : points)
        {
            cout << fixed << setprecision(2) << point << " ";
        }

        cout << "\n";

    } catch(const exception &e)
    {
        cout << "Validation error: " << e.what() << "\n";
    }

    return 0;
}
