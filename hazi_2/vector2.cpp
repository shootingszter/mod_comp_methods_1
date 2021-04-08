#include <iostream>
#include <ostream>
//általam csinált header "" közt
#include "vector2.h"

//meghívom a headerben definiált műveleteket

int main()
{
    Vector2<double> v1{}, v2{};

    std::cout << "Enter vector 1:\n";
    std::cin >> v1;
    
    std::cout << "Enter vector 2:\n";
    std::cin >> v2;

    Vector2<double> sum = operator+(v1, v2);
    std::cout << "vector1 + vector2 = " << sum << "\n";

    std::cout << "--\n";


    Vector2<double> sub = operator-(v1, v2);
    std::cout << "vector1 - vector2 = " << sub << "\n";

    std::cout << "--\n";


    double scalar;
    std::cout << "Enter a scalar:\n";
    std::cin >> scalar;

    Vector2<double> scalar1 = operator*(v1, scalar);
    Vector2<double> scalar2 = operator*(v2, scalar);

    std::cout << "scalar1 " << scalar1 << "\n";
    std::cout << "scalar2 " << scalar2 << "\n";

    std::cout << "--\n";


    double dot_prod = dot(v1, v2);
    std::cout << "dot product " << dot_prod << "\n";

    std::cout << "--\n";


    double length1 = length(v1);
    double length2 = length(v2);

    std::cout << "length 1 " << length1 << "\n";
    std::cout << "length 2 " << length2 << "\n";

    std::cout << "--\n";

   
    double sq1 = sqlength(v1);
    double sq2 = sqlength(v2);

    std::cout << "square length 1 " << sq1 << "\n";
    std::cout << "square length 2 " << sq2 << "\n";

    std::cout << "--\n";


    Vector2<double> norm1 = normalize(v1);
    Vector2<double> norm2 = normalize(v2);
    std::cout << "first vector normalization " << norm1 << "\n";
    std::cout << "second vector normalization " << norm2 << "\n";


    return 0;
}

