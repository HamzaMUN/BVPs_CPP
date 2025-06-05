#include <iostream>
#include <vector>
#include <stdexcept>
#include "uniformly_spaced_points.h"


using namespace std;


void validate_input(int a, int b, int N)
{
    // Validate the user input for the interval (a and b) and number of interior points (N).
    if(a >= b)
    {
        throw invalid_argument("The start of the interval (a) must be less than the end of the interval (b).");
    }

    if(N < 1)
    {
        throw invalid_argument("The number of interior points (N) must be a positive integer.");
    }
}

vector<double> gen_uniform_points(int a, int b, int N)
{
    // Generate uniformly spaced points in the interval [a, b] with N interior points.
    vector<double> points;
    double step = static_cast<double>(b - a) / (N + 1);

    for(int i = 0; i <= N + 1; i++)
    {
        points.push_back(a + i * step);
    }

    return points;
}

void get_user_input(int &a, int &b, int &N)
{
    // Prompt the user to input the start (a), end (b), and number (N) of interior points.
    cout << "Enter the start of the interval (a): ";
    cin >> a;
    cout << "Enter the end of the interval (b): ";
    cin >> b;
    cout << "Enter the number of interior points (N): ";
    cin >> N;
}
