#include <vector>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Filter
{
public:
    unsigned char *createCanvas(int width, int height)
    {
        int size = width * height * 3;
        canvas = new unsigned char[size];
        for (unsigned char *p = canvas; p <= canvas + size; p += 3)
        {
            *p = (uint8_t)0;
            *(p + 1) = (uint8_t)0;
            *(p + 2) = (uint8_t)0;
        }
        stbi_write_jpg("canvas.jpg", width, height, 3, canvas, 100);
        return canvas;
    }

    unsigned char *getRow(unsigned char *tile, int width, int channels, int rowNumber)
    {
        row = new unsigned char[width * channels];
        for (unsigned char *p = tile; p <= tile + (rowNumber * width * channels); p += channels)
        {
            *row = *p;
            *(row + 1) = *(p + 1);
            *(row + 2) = *(p + 2);
            row += channels;
        }
        return row;
    }

    void placeTileOnCanvas(unsigned char *tile, int width, int height)
    {
        for (unsigned char *p = canvas + (100 * width * 3); p <= canvas + (150 * width * 3); p += 3)
        {
            *p = (uint8_t)255;
            *(p + 1) = (uint8_t)0;
            *(p + 2) = (uint8_t)0;
        }
        stbi_write_jpg("canvas.jpg", 1100, 1100, 3, canvas, 100);
    }

private:
    unsigned char *row = nullptr;
    unsigned char *canvas = nullptr;
};
