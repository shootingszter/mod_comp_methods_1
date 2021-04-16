#include <iostream>
#include <ostream>
#include <math.h>
#include <fstream>
#include "Richardson.h"


int main()
{

    std::cout << "Enter F:\n";
    std::cin >> F;
    
    std::cout << "Enter q:\n";
    std::cin >> q;

    std::cout << "Enter a:\n";
    std::cin >> a;
    
    std::cout << "Enter h:\n";
    std::cin >> h;

    std::ofstream ofile;

    ofile.open ("output.txt");

    ofile << "Midpoint integral: " << midpoint(length, 0.0, 200.0, 269) << ",\t";
    ofile << "Trapezoidal integral: " << trap(0.0, 200.0, 380) << ",\t";
    ofile << "Simpson's 1/3 rule: " << Simpson(0.0, 200.0, 4);

    ofile.close();
    return 0;
}