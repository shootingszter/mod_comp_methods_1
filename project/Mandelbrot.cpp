#include <ostream>
#include <iostream>
#include <fstream>

/*
while (x*x + y*y < 2*2 AND iteration < max_iteration)
{
    xtemp = x*x - y*y +x0
        y = 2 * x*y + y0
        x = xtemp
        iteration = iteration + 1
}*/

int main()
{
    //get the required input values from file

    std::ifstream fin("input.txt");
    int imageWidth, imageHeight, maxN;
    double minR, maxR, minI, maxI;
    if (!fin)
    {
        std::cout << "COuld not open file!" << std::endl;
        std::cin.ignore();
        return 0;
    }

    fin >> imageWidth >> imageHeight;
    //open the output file, write the header

    // for every pixel...
    //...find the real and imaginary values for c, corresponding to that x, y pixel in the image
    //...find the number of iterations in the mandekbrot formula using that c
    //...map the resulting number to an rgb value
    //...output it to the image


}