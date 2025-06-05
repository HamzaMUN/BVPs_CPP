#ifndef UNIFORMLY_SPACED_POINTS_H_INCLUDED
#define UNIFORMLY_SPACED_POINTS_H_INCLUDED

#include <vector>

// Declaration of gen_uniform_points function where a is start of the interval, b is the end of the interval and N is the total number of interior points.
std::vector<double> gen_uniform_points(int a, int b, int N);

// Declaration of validate_input function which validates user input
void validate_input(int a, int b, int N);

// Declaration of gen_user_input function which stores user inputs
void get_user_input(int &a, int &b, int &N);

#endif // UNIFORMLY_SPACED_POINTS_H_INCLUDED
