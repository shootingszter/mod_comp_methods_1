#include <ostream>
#include <iostream>
#include <fstream>
#include <math.h>


template <typename I, typename D>

D mapToReal(I x, I imageWidth, D minR, D maxR)
{
    double range = maxR - minR;

    return x*(range/imageWidth) + minR;

}


template <typename I, typename D>

double mapToImaginary(I y, I imageHeight, D minI, D maxI)
{
    double range = maxI - minI;

    return y*(range/imageHeight) + minI;
}


template <typename I, typename D>

int findMandelbrot(D cr, D ci, I max_iterations)
{
    int i = 0;
    double zr = 0.0, zi = 0.0;

    while (i < max_iterations && zr * zr + zi * zi < 4.0)
    {
        double temp = zr * zr - zi * zi + cr;

        zi = 2.0 * zr * zi + ci;
        zr = temp;

        i++;
    }

    return i;

}