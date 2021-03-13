#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

using namespace std; //hogy ne kelljen minden alkalommal kiírni, hogy std ::

//Find the square root of 'num' by starting the iteration from 'x0'

template<typename F, typename T>

T deriv(F f, int n, T x0, T x1)
{
   return (f*(x1-x0))/ n;
}

template<typename F, typename T>

double Newton(F f, T deriv, double x0, double e)
{
    double x1{};

    while(true) 
    {
        x1 = x0 - f(x0) / deriv(f, x0, )

        if(abs( x1 - x0 ) <= e ) break;

        x0 = x1;
    }

    return x1;
}
/*
Newton [](double x){ return x*x-612.0; }
       [](double x){ return 2.0*x; }, 10.0);
*/
int main()
{
    double Newton = [](double x){ return x*x-612.0; }

    return Newton(x);
}