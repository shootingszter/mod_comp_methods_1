#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdlib.h>

using namespace std; //hogy ne kelljen minden alkalommal kiírni, hogy std ::
 

template<typename F, typename T, typename G>

//f- the function
//df- derivative of the function
//x0- initial guess

double Newton(F f, G df, T x0)
{
    double x1{}; //initializing 
    double e = 1e-3; //epsilon

    while(true) 
    {
        x1 = x0 - f(x0) / df(x0);

        if(abs( x1 - x0 ) <= e ) break;
        x0 = x1;
    }

    return x1;
}

int main()
{
    auto f = [](double x){ return x*x-612.0; };
    auto df = [](double x){ return 2.0*x; };
    double x0 = 10.0;
    
    double output = Newton(f, df, x0);
    cout<< "The root is:" <<output<<endl;

    return 0;
}