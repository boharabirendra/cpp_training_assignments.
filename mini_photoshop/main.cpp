#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <vector>
#include <cstdint>
#include <iostream>
#include <algorithm>

#include "./types/structs.h"
#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

std::vector<RGB> getNeighbors(const std::vector<std::vector<RGB>> &image, int x, int y)
{
    std::vector<RGB> neighbors;
    int rows = image.size();
    int cols = image[0].size();

    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols)
            {
                neighbors.push_back(image[nx][ny]);
            }
        }
    }
    return neighbors;
}

uint8_t computeMedian(std::vector<uint8_t> &values)
{
    std::sort(values.begin(), values.end());
    int n = values.size();
    return values[n / 2];
}

std::vector<std::vector<RGB>> applyMedianFilter(const std::vector<std::vector<RGB>> &image)
{
    int rows = image.size();
    int cols = image[0].size();
    std::vector<std::vector<RGB>> filteredImage(rows, std::vector<RGB>(cols));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            std::vector<RGB> neighbors = getNeighbors(image, i, j);

            std::vector<uint8_t> reds, greens, blues;
            for (const auto &neighbor : neighbors)
            {
                reds.push_back(neighbor.r);
                greens.push_back(neighbor.g);
                blues.push_back(neighbor.b);
            }

            filteredImage[i][j].r = computeMedian(reds);
            filteredImage[i][j].g = computeMedian(greens);
            filteredImage[i][j].b = computeMedian(blues);
        }
    }

    return filteredImage;
}

std::vector<std::vector<RGB>> convertTo2D(const unsigned char *imageData, int width, int height)
{
    std::vector<std::vector<RGB>> output;

    for (int i = 0; i < height; ++i)
    {
        std::vector<RGB> row;
        for (int j = 0; j < width * 3; j += 3)
        {
            RGB color;
            color.r = imageData[i * width * 3 + j + 0];
            color.g = imageData[i * width * 3 + j + 1];
            color.b = imageData[i * width * 3 + j + 2];
            row.push_back(color);
        }
        output.push_back(row);
    }

    return output;
}

void saveToPNG(const std::vector<std::vector<RGB>> &imageData, int width, int height, const char *filename)
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

int main()
{
    int width, height, channels;
    unsigned char *imageData = stbi_load("./noise.png", &width, &height, &channels, 3);

    if (!imageData)
    {
        std::cerr << "Failed to load image!" << std::endl;
        return -1;
    }

    auto mat = convertTo2D(imageData, width, height);

    auto filteredImage = applyMedianFilter(mat);

    saveToPNG(filteredImage, width, height, "filtered_image.png");

    stbi_image_free(imageData);

    return 0;
}
