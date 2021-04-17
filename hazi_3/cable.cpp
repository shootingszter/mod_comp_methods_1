#include <iostream>
#include <ostream>
#include <math.h>
#include <fstream>
#include "Richardson.h"


int main()
{
    /*
    Richardson<double> 

    std::cout << "Enter F:\n";
    std::cin >> Richardson<double> F;
    
    std::cout << "Enter q:\n";
    std::cin >> Richardson<double> q;

    std::cout << "Enter a:\n";
    std::cin >> Richardson<double> a;
    
    std::cout << "Enter h:\n";
    std::cin >> Richardson<double> h;
    */
    

    std::ofstream ofile;

    ofile.open ("output.txt");

    ofile << "Midpoint integral: " << midpoint(length, 0.0, 200.0, 269) << ",\t";
    ofile << "Trapezoidal integral: " << trap(length, 0.0, 200.0, 380) << ",\t";
    ofile << "Simpson's 1/3 rule: " << Simpson(length, 0.0, 200.0, 4);

    ofile.close();
    return 0;
}