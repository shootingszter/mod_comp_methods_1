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

double mapToReal(int x, int imageWidth, double minR, double maxR)
{
    double range = maxR - minR;

    return x*(range/imageWidth) + minR;

}

double mapToImaginary(int y, int imageHeight, double minI, double maxI)
{
    double range = maxI - minI;

    return y*(range/imageHeight) + minI;
}

int findMandelbrot(double cr, double ci, int max_iterations)
{
    int i = 0;
    double zr = 0.0, zi = 0.0;

    while (i < max_iterations && zr * zr + zi * zi < 4.0)
    {
        double temp = zr * zr - zi * zi + cr;

        zi = 2.0 * zr * zi + ci;
        zr = temp;

        i++;
    }

    return i;

}

int main()
{
    //get the required input values from file

    std::ifstream fin("input.txt");

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
    fin.close();

    //open the output file, write the header
    std::ofstream fout("output.ppm");

    fout << "P3" << std::endl;
    fout << imageWidth << " " << imageHeight << std::endl;
    fout << "256" << std::endl;
    
    // for every pixel...
    for (int y = 0; y < imageHeight; y++) //rows
    {
        for (int x = 0; x < imageWidth; x++)
        {
            //...find the real and imaginary values for c, corresponding to that x, y pixel in the image
            double cr = mapToReal(x, imageWidth, minR, maxR);
            double ci = mapToImaginary(y, imageHeight, minI, maxI);

            //...find the number of iterations in the mandekbrot formula using that c
            int n = findMandelbrot(cr, ci, maxN);
            //...map the resulting number to an rgb value
            int r = (n % 256); // change for more interesting colors
            int g = (n % 256);
            int b = (n % 256);

            //...output it to the image

            fout << r << " " << g << " " << b << " ";
        }

        fout << std::endl;
    }
    
    fout.close();
    std::cout << "Finished!" << std::endl;
    return 0;

}