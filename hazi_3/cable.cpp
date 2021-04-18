#include <iostream>
#include <ostream>
#include <math.h>
#include <fstream>
#include "Richardson.h"



int main()
{

    
    const double x = 4;
    const int n = 1000000;

    //double len = length(shape<double>(4, F, q, a, h));
    
    double mpint = midpoint<double>(length, 0.0, 200.0, n);
    
    double tpint = trap<double>(length, 0.0, 200.0, n);
    
    double spint = Simpson<double>(length, 0.0, 200.0, n);
    

    std::ofstream ofile ("output.txt");

    if (ofile.is_open()) {
        
        ofile << "Középpontos integrál: " << mpint << "\n ";
        ofile << "Trapéz integrál: " << tpint << "\n ";
        ofile << "Simpson 1/3 integrál: " << spint;
            
        ofile.close();
    }

    return 0;
}