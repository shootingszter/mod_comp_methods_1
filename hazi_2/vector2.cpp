#include <iostream>
#include <ostream>
#include <math.h>
#include <vector2.h>

int main()
{
    Vector2 v = {1.0, 2.0};
    Vector2 u = {4.0, -2.0};
    auto w = v + u;
    std::cout<<w.x<<" "<<w.y<<"\n";
    return 0;
}

