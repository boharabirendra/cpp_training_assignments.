#include <iostream>
#include <algorithm>

#include "../include/MedianFilter.h"

std::vector<std::vector<RGB>> MedianFilter::apply(std::vector<std::vector<RGB>> &image)
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

std::vector<RGB> MedianFilter::getNeighbors(const std::vector<std::vector<RGB>> &image, int x, int y)
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

uint8_t MedianFilter::computeMedian(std::vector<uint8_t> &values)
{
    std::sort(values.begin(), values.end());
    int n = values.size();
    return values[n / 2];
}