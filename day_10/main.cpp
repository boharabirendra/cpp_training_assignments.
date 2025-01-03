#include "Filter.h"

int main()
{
    int width, height, channels;
    unsigned char *smallImage = stbi_load("./tile1.jpg", &width, &height, &channels, 3);
    if (smallImage == nullptr)
    {
        std::cout << "Failed to load image!" << std::endl;
        return -1;
    }

    Filter filter;

    // Set the target canvas size (1100x1100)
    int canvasWidth = 11000;
    int canvasHeight = 11000;

    // Create a blank canvas (1100x1100)
    auto canvas = filter.createCanvas(canvasWidth, canvasHeight);

    filter.placeTileOnCanvas(smallImage, width, height, 10, 10);

    stbi_image_free(smallImage);

    return 0;
}