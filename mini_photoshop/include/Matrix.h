#include <vector>
#include <iostream>

#include "./types/structs.h"

std::vector<std::vector<RGB>> convertTo2D(const unsigned char *imageData, int width, int height)
{
    std::vector<std::vector<RGB>> output;
    int length = width * height * 3;
    RGB color;

    for (int i = 0; i < height; ++i)
    {
        std::vector<RGB> row;
        for (int j = 0; j < width * 3; j += 3)
        {
            color.r = imageData[i * width * 3 + j + 0];
            color.g = imageData[i * width * 3 + j + 1];
            color.b = imageData[i * width * 3 + j + 2];
            row.emplace_back(color);
        }
        output.emplace_back(row);
    }

    return output;
}
