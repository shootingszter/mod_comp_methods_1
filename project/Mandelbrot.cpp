#include <iostream>
#include <ostream>
#include <cmath>
#include <complex>

template<typename T>

auto Mandelbrot(T c, T max_iter)
{
    int z = c;

    for (int i = 0; i < max_iter; i++)
    {
        if (abs(z) > 2)
        {
            return i;
        }
            
        z = z*z + c;
    } 

    return 0;
}