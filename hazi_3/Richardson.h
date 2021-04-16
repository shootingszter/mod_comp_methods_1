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


template<typename T>

T lenght(T x)
{
    auto diff = R_6(1, x);
    
    return sqrt(1 + (diff*diff));
}


template<typename T>

T midpoint(T x, double a, double b, int n)
{
    T integral;

    double delta = (b-a) / n;

    for (int i=0; i < n; i++)
    {
        integral += a + (i + 0.5) * delta;
    }

    return delta * integral;
}


template<typename T>

T trap(double a, double b, int n)
{
    double delta = (b-a) / n;

    T sum = (a+b) / 2;

    for (int i=0; i < n; i++)
    {
        sum += a + i*delta;
    }
    
    return  sum*delta;
}


template<typename T>

T Simpson(double a, double b, int n)
{
    double delta = (b-a) / n;
    T sum_i = 0;
    T sum_j = 0;


    for (int i=0; i < n; i++)
    {
        sum_i += a + 2*i*delta;
    }


    for (int j=0; j < n; j++)
    {
        sum_j += a + (2*j-1)*delta;
    }
    

    T lol = (delta/3)*(a + 2*sum_i + 4*sum_j + b);

    return lol;
}