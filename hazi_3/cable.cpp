#include <iostream>
#include <ostream>
#include <math.h>
#include <fstream>
#include "Richardson.h"
// including the header 


int main()
{
    // declaring necessary values
    const double x = 2;
    const int n = 1000;

    // using the integration functions with parameteres
    double mid = midpoint<double>(length, 0.0, 200.0, n);
    double tra = trap<double>(length, 0.0, 200.0, n);
    double simp = Simpson<double>(length, 0.0, 200.0, n);
    
    // printing the outputs into a txt file
    std::ofstream ofile ("output.txt");

    if (ofile.is_open()) {
        
        ofile << "Midpoint integral: " << mid << ",\n ";
        ofile << "Trapezoid integral: " << tra << ",\n ";
        ofile << "Simpson's 1/3 integral: " << simp;
            
        ofile.close();
    }

    return 0;
}