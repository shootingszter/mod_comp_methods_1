#include <iostream>
#include <ostream>
#include <math.h>


double shape(double x, double F, double q, double a, double h)
{
    return F/q * (cosh( (q/F)*x )) - cosh( ( (q*a)/(2*F) )+h);
}

template<typename T>

T R_2(T x, double c) //h a képletben
{
    return (shape(x+c) - shape(x-c)) / (2*c);
}

template<typename T>

T R_4(T x, double c) //h a képletben
{
    return (4*R_2(x, c) - R_2(x, 2*c)) / 3;
}

// function to perform 6th order Richardson 

template<typename T>

T R_6(T x)
{
    double c = 1;

    return (16*R_4(x, c) - R_4(x, 2*c)) / 15;
}

