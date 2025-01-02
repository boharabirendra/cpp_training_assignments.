#include <random>

#include "../include/Noise.h"

std::vector<std::vector<RGB>> Noise::apply(std::vector<std::vector<RGB>> &image)
{
    int rows = image.size();
    int cols = image[0].size();

    int totalPixel = rows * cols;

    int amountOfPixelToBeChangedToAddNoise = totalPixel * 0.5;

    for (int i = 0; i < amountOfPixelToBeChangedToAddNoise; i++)
    {
        Coordinate cor = getRandomPixelLocation(rows, cols);

        image[cor.y][cor.x].r = (uint8_t)0;
        image[cor.y][cor.x].g = (uint8_t)0;
        image[cor.y][cor.x].b = (uint8_t)0;
    }
    return image;
}

Coordinate Noise::getRandomPixelLocation(int rows, int cols)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> disX(0, cols - 1);
    std::uniform_int_distribution<> disY(0, rows - 1);

    Coordinate cor;
    cor.x = disX(gen);
    cor.y = disY(gen);

    return cor;
}