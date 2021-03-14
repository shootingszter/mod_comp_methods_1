#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

using namespace std; //hogy ne kelljen minden alkalommal kiírni, hogy std ::
 
/*
deriváló rutin, amiről kiderült, hogy haszontalan

T deriv(F f, int n, T x0, T x1)
{
   return (f*(x1-x0))/ n;
}
*/
template<typename T>

T function(T x) //a közelíteni kívánt függvény
{
    return x*x*x - x*x + 2;
}

template<typename D>

D dx(D x) //...és az annak deriváltjával visszatérő függvény
{
    return 3*x*x - 2*x;
}

template<typename F, typename T>

double Newton(F function, T df, double x0, double e)
{
    double x1{};

    while(true) 
    {
        x1 = x0 - function(x0) / df(x0);

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