#include <vector>
#include <cstdint>
#include <iostream>

#include "./include/Image.h"
#include "./include/FilterFactory.h"

int main()
{
    system("clear");
    std::cout << "Mini CLI based photoshop\n";
    std::cout << "------------------------\n\n";

    int opt;
    std::cout << "1. Median filter \n";
    std::cout << "2. Gray scale \n";
    std::cout << "3. Add Noise \n";
    std::cout << "\nChoose the option: ";
    std::cin >> opt;

    Image image;
    Filter *filter = FilterFactory::getFilter(opt);

    try
    {
        auto imageData = image.load("./car.png");
        if (!imageData)
        {
            return -1;
        }
        auto mat = image.convertTo2D(imageData);
        auto filteredImage = filter->apply(mat);
        image.save(filteredImage, "./output_image.png");
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
