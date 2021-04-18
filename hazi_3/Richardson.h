#include <iostream>
#include <ostream>
#include <math.h>


//declaring the given parameters
const double F = 900.0;
const double q = 1.8;
const double a = 200.0;
const double h = 35.0;


// function that describe the shape of the cable

double shape(double x)
{
    return F/q * (cosh( (q/F)*x )) - cosh( ( (q*a)/(2*F) )+h);
}


// function to perform 2nd order Richardson

template<typename T>

T R_2(T x, double c)
{
    return (shape(x+c) - shape(x-c)) / (2*c);
}


// function to perform 4th order Richardson

template<typename T>

T R_4(T x, double c)
{
    return (4*R_2(x, c) - R_2(x, 2*c)) / 3;
}


// function to perform 6th order Richardson 

template<typename T>

T R_6(T x, double c)
{
    return (16*R_4(x, c) - R_4(x, 2*c)) / 15;
}


// function that returns the length of the cable

template<typename T>

T length(T x)
{
    auto diff = R_6(x, 1);
    
    return sqrt(1 + (diff*diff));
}


// midpoint integration

template<typename T>

T midpoint(T (*f)(T x), double a, double b, int n)
{
    double integral = 0;

    double delta = (b-a) / n;

    for (int i=0; i < n; i++)
    {
        integral += f(a + (i + 0.5) * delta);
    }

    return delta * integral;
}


// Trapezoidal integration

template<typename T>

T trap(T (*f)(T x), double a, double b, int n)
{
    double delta = (b-a) / n;

    double sum = (a+b) / 2;

    for (int i=0; i < n; i++)
    {
        sum += f(a + i*delta);
    }
    
    return  sum*delta;
}


// 1/3 Simpson's rule

template<typename T>

T Simpson(T (*f)(T x), double a, double b, int n)
{
    double delta = (b-a) / n;
    double sum_i = 0;
    double sum_j = 0;


    for (int i=0; i < n; i++)
    {
        sum_i += f(a + 2*i*delta);
    }


    for (int j=0; j < n; j++)
    {
        sum_j += f(a + (2*j-1)*delta);
    }
    

    double lol = (delta/3)*(a + 2*sum_i + 4*sum_j + b);

    return lol;
}