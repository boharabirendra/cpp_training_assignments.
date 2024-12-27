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

    void placeTileOnCanvas(unsigned char *tile, int tileWidth, int tileHeight, int gapX, int gapY)
    {
        int canvasWidth = 1100;
        int canvasHeight = 1100;

        for (int startY = 0; startY < canvasHeight; startY += tileHeight + gapY)
        {
            for (int startX = 0; startX < canvasWidth; startX += tileWidth + gapX)
            {
                for (int y = 0; y < tileHeight; y++)
                {
                    if (startY + y >= canvasHeight)
                        break;

                    for (int x = 0; x < tileWidth; x++)
                    {
                        if (startX + x >= canvasWidth)
                            break;

                        int tileIndex = (y * tileWidth + x) * 3;
                        int canvasIndex = ((startY + y) * canvasWidth + (startX + x)) * 3;

                        canvas[canvasIndex] = tile[tileIndex];
                        canvas[canvasIndex + 1] = tile[tileIndex + 1];
                        canvas[canvasIndex + 2] = tile[tileIndex + 2];
                    }
                }
            }
        }

        stbi_write_jpg("canvas.jpg", canvasWidth, canvasHeight, 3, canvas, 100);
    }

    ~Filter()
    {
        delete[] row;
        delete[] canvas;
    }

private:
    unsigned char *row = nullptr;
    unsigned char *canvas = nullptr;
};
