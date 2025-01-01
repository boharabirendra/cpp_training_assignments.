#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "../include/Image.h"
#include "../stb/stb_image.h"
#include "../stb/stb_image_write.h"

unsigned char *Image::load(const char *imagePath)
{
    std::cout << imagePath << std::endl;
    imageData = stbi_load(imagePath, &width, &height, &channels, 3);
    if (!imageData)
    {
        std::cerr << "Failed to load image!" << std::endl;
        return nullptr;
    }
    return imageData;
}

void Image::save(const std::vector<std::vector<RGB>> &imageData, const char *filename)
{
    std::vector<unsigned char> imageFlat;
    imageFlat.reserve(width * height * 3);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            const RGB &color = imageData[i][j];
            imageFlat.push_back(color.r);
            imageFlat.push_back(color.g);
            imageFlat.push_back(color.b);
        }
    }

    if (stbi_write_png(filename, width, height, 3, imageFlat.data(), width * 3))
    {
        std::cout << "Image saved successfully to " << filename << std::endl;
    }
    else
    {
        std::cout << "Failed to save image!" << std::endl;
    }
}

std::vector<std::vector<RGB>> Image::convertTo2D(const unsigned char *imageData)
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