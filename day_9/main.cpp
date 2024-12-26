

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <vector>
#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

struct coordinate
{
    int x;
    int y;
};

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

void convertToGrayscale(std::vector<std::vector<RGB>> &imageData, int width, int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            RGB &color = imageData[i][j];
            float gray = color.r * 0.2989f + color.g * 0.5870f + color.b * 0.1140f;
            color.r = gray;
            color.g = gray;
            color.b = gray;
        }
    }
}

void convertToColor(std::vector<std::vector<RGB>> &imageData, int width, int height)
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            RGB &color = imageData[i][j];
            color.r = std::min(color.r * 1.7f, 255.0f);
            color.g = std::min(color.g * 1.3f, 255.0f);
            color.b = std::min(color.b * 0.9f, 255.0f);
        }
    }
}

void sobelEdgeDetection(std::vector<std::vector<RGB>> &imageData, int width, int height)
{
    const int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}};
    const int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}};

    std::vector<std::vector<RGB>> originalImage = imageData;

    for (int i = 1; i < height - 1; ++i)
    {
        for (int j = 1; j < width - 1; ++j)
        {
            float gx = 0.0f;
            float gy = 0.0f;

            for (int k = -1; k <= 1; ++k)
            {
                for (int l = -1; l <= 1; ++l)
                {
                    float intensity = originalImage[i + k][j + l].r;
                    gx += Gx[k + 1][l + 1] * intensity;
                    gy += Gy[k + 1][l + 1] * intensity;
                }
            }

            float gradientMagnitude = std::sqrt(gx * gx + gy * gy);

            gradientMagnitude = std::min(std::max(gradientMagnitude, 0.0f), 255.0f);

            imageData[i][j].r = gradientMagnitude;
            imageData[i][j].g = gradientMagnitude;
            imageData[i][j].b = gradientMagnitude;
        }
    }
}

void drawRect(std::vector<std::vector<RGB>> &input, int x, int y, int width, int height, RGB stroke = {0, 0, 0}, RGB fill = {0xff, 0xff, 0xff})
{
    for (int i = x; i < x + width; ++i)
    {
        input[y][i] = stroke;
        input[y + height][i] = stroke;
    }
    for (int i = y; i < y + height; ++i)
    {
        input[i][x] = stroke;
        input[i][x + width] = stroke;
    }
    for (int i = x + 1; i < x + width; ++i)
    {
        for (int j = y + 1; j < y + height; ++j)
        {
            input[j][i] = fill;
        }
    }
}

void drawPloy(std::vector<std::vector<RGB>> &input, int width, int height, const std::vector<coordinate> &coor, RGB stroke, RGB fill)
{
}

std::vector<std::vector<RGB>> rotateImage90(const std::vector<std::vector<RGB>> &image)
{
    int width = image.size();
    int height = image[0].size();

    std::vector<std::vector<RGB>> rotatedImage(height, std::vector<RGB>(width));

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            rotatedImage[j][width - i - 1] = image[i][j];
        }
    }

    return rotatedImage;
}

std::vector<std::vector<RGB>> combineImages(std::vector<std::vector<RGB>> &tigerData, std::vector<std::vector<RGB>> &trafficData)
{
    int height_1 = tigerData.size();
    int width_1 = tigerData[0].size();
    int height_2 = trafficData.size();
    int width_2 = trafficData[0].size();

    int width = std::min(width_1, width_2);
    int height = std::min(height_1, height_2);

    std::vector<std::vector<RGB>> combinedImage(height, std::vector<RGB>(width));

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            combinedImage[i][j].r = (tigerData[i][j].r + trafficData[i][j].r) / 2;
            combinedImage[i][j].g = (tigerData[i][j].g + trafficData[i][j].g) / 2;
            combinedImage[i][j].b = (tigerData[i][j].b + trafficData[i][j].b) / 2;
        }
    }

    return combinedImage;
}

int main()
{
    int width_1, height_1, width_2, height_2, channels;

    unsigned char *tigerData = stbi_load("./images/tiger.jpg", &width_1, &height_1, &channels, 3);
    if (tigerData == nullptr)
    {
        std::cout << "Failed to load tiger image\n";
        return 1;
    }
    unsigned char *trafficData = stbi_load("./images/traffic.jpg", &width_2, &height_2, &channels, 3);
    if (trafficData == nullptr)
    {
        std::cout << "Failed to load traffic image\n";
        stbi_image_free(tigerData);
        return 1;
    }

    auto tiger2DData = convertTo2D(tigerData, width_1, height_1);
    auto traffic2Data = convertTo2D(trafficData, width_2, height_2);

    auto combinedImage = combineImages(tiger2DData, traffic2Data);

    saveToPNG(combinedImage, combinedImage[0].size(), combinedImage.size(), "combinedImage.png");

    stbi_image_free(tigerData);
    stbi_image_free(trafficData);

    return 0;
}

// int height = 400;
// int width = 500;
// std::vector<std::vector<RGB>> image(height, std::vector<RGB>(width, {0xff, 0xff, 0xff}));
// drawRect(image, 100, 100, 200, 50, {0, 0, 0}, {0xff, 0, 0});