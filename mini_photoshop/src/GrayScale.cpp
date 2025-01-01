#include "../include/GrayScale.h"

std::vector<std::vector<RGB>> GrayScale::apply(std::vector<std::vector<RGB>> &image)
{
    int height = image.size();
    int width = image[0].size();
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            RGB &color = image[i][j];
            float gray = color.r * 0.2989f + color.g * 0.5870f + color.b * 0.1140f;
            color.r = gray;
            color.g = gray;
            color.b = gray;
        }
    }

    return image;
}