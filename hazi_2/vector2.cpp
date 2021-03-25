#include <iostream>
#include <ostream>
#include "vector2.h"

//template<typename T>

int main()
{
    Vector2<double> v1{}, v2{};

    std::cout << "Enter vector 1:\n";
    std::cin >> v1;
    std::cout << "Enter vector 2:\n";
    std::cin >> v2;

    Vector2<double> sum = operator+(v1, v2);
    std::cout << "vector1 + vector2 = " << sum << "\n";

    return 0;
}

