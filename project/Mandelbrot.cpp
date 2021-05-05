#include <ostream>
#include <iostream>
#include <fstream>
#include <math.h>
//including the header 
#include "Mandelheader.h"



int main()
{
    //declare used paramteres
    int imageWidth = 1000;
    int imageHeight = 1000;
    int maxN = 1000;

    double minR, maxR, minI, maxI;

    //these ar the input prameteres that can be changed by the user
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

    fout << "P3" << std::endl; //generate an RGB color image
    fout << imageWidth << " " << imageHeight << std::endl; //size
    fout << "256" << std::endl; //the maximum value for each color

    // for every pixel...
    for (int y = 0; y < imageHeight; y++) //rows
    {
        for (int x = 0; x < imageWidth; x++) //cols
        {
            //find the real and imaginary values for c, corresponding to that x, y pixel in the image
            double cr = mapToReal<double>(x, imageWidth, minR, maxR);
            double ci = mapToImaginary<double>(y, imageHeight, minI, maxI);

            //find the number of iterations in the mandelbrot formula using that c
            int n = findMandelbrot<int>(cr, ci, maxN);

            //map the resulting number to an rgb value
            //this results in an orange- yellow- pink- green palette
            int r = (n * n % 256); 
            int g = (n * n % 100);
            int b = (n % 119);

            //output it to the image
            fout << r << " " << g << " " << b << " ";
        }

        fout << std::endl;
    }
    
    fout.close();
    std::cout << "Finished!" << std::endl; //sign that the output image is done
    
    return 0;

}