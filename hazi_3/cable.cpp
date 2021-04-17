#include <iostream>
#include <ostream>
#include <math.h>
#include <fstream>
#include "Richardson.h"


int main()
{
    
    double F = 900.0;
    double q = 1.8;
    double a = 200.0;
    double h = 35.0;

    std::ofstream ofile;

    ofile.open ("output.txt");

    ofile << "Midpoint integral: " << midpoint(length, 0.0, 200.0, 269) << ",\t";
    ofile << "Trapezoidal integral: " << trap(length, 0.0, 200.0, 380) << ",\t";
    ofile << "Simpson's 1/3 rule: " << Simpson(length, 0.0, 200.0, 4);

    ofile.close();
    return 0;
}