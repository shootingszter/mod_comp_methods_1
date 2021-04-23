#include <iostream>
#include <ostream>
#include <math.h>
#include <stdio.h>
#include <fstream>

double d_fun(double y)
{
    return 1 + y*y;
}

template<typename State, typename T, typename RHS>

auto Newton(State y0, T t0, T t1, T h, RHS f)
{
    T t = t0;
    State y = y0;

    while (t < t1) 
    {
        y = y + h * f(t, y);
        t = t + h;
    }
    
    return y;
}

template<typename State, typename T, typename RHS> //, typename Callback

auto solve_rk4(State y0, T t0, T t1, T h, RHS f) //, Callback cb)
{
    T t = t0; 
    State y = y0;

    while(t < t1)
    {
        if(t + h > t1)
        {
            h = t1 - t;
        }
        
        State k1 = f(t, y);
        State k2 = f(t + h * (T)0.5, y + (h * (T)0.5) * k1);
        State k3 = f(t + h * (T)0.5, y + (h * (T)0.5) * k2);
        State k4 = f(t + h, y + h * k3);
        y = y + (k1 + k4 + (T)2 * (k2 + k3)) * (h / (T)6);
        t = t + h;
        //cb(t, y);
    }
    return y;
}

int main()
{
    double t0 = 0.0;
    double t1 = 1.0;
    double y0 = 0.0;
    double h = 0.001;

    double analitic = tan(t1);
    double oldton = Newton(y0, t0, t1, h, d_fun);
    double RK4 = solve_rk4(y0, t0, t1, h, d_fun);

    std::ofstream ofile ("output.txt");

    if (ofile.is_open()) {
        
        ofile << "Analitic solution: " << analitic << ",\n ";
        ofile << "Solution with Newton's method: " << oldton << ",\n ";
        ofile << "Solution with 4th order Runge Kutta: " << RK4;
            
        ofile.close();
    }
    return 0;

}