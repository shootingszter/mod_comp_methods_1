#include <ostream>
#include <iostream>
#include <fstream>
#include <math.h>

#include "Mandelheader.h"



int main()
{
    //get the required input values from file

    /* std::ifstream fin("input.txt");

    int imageWidth, imageHeight, maxN;
    double minR, maxR, minI, maxI;
    
    if (!fin)
    {
        std::cout << "Could not open file!" << std::endl;
        std::cin.ignore();
        return 0;
    }

    fin >> imageWidth >> imageHeight >> maxN;
    fin >> minR >> maxR >> minI >> maxI;
    fin.close(); */

    int imageWidth = 1000;
    int imageHeight = 1000;
    int maxN = 1000;

    double minR, maxR, minI, maxI;

    std::cout << "Enter minReal:\n";
    std::cin >> minR;
    
    std::cout << "Enter maxReal:\n";
    std::cin >> maxR;

    std::cout << "Enter minImaginary:\n";
    std::cin >> minI;
    
    std::cout << "Enter maxImaginary:\n";
    std::cin >> maxI;

    //open the output file, write the header
    std::ofstream fout("Mandelplot.ppm");

    fout << "P3" << std::endl;
    fout << imageWidth << " " << imageHeight << std::endl;
    fout << "256" << std::endl;

    // for every pixel...
    for (int y = 0; y < imageHeight; y++) //rows
    {
        for (int x = 0; x < imageWidth; x++)
        {
            //...find the real and imaginary values for c, corresponding to that x, y pixel in the image
            double cr = mapToReal<double>(x, imageWidth, minR, maxR);
            double ci = mapToImaginary<double>(y, imageHeight, minI, maxI);

            //...find the number of iterations in the mandekbrot formula using that c
            int n = findMandelbrot<int>(cr, ci, maxN);
            //...map the resulting number to an rgb value
            int r = (n * n % 256); // change for more interesting colors
            int g = (n * n % 100);
            int b = (n % 119);

            //...output it to the image

            fout << r << " " << g << " " << b << " ";
        }

        fout << std::endl;
    }
    
    fout.close();
    std::cout << "Finished!" << std::endl;
    return 0;

}