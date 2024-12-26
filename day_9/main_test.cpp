#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <vector>
#include <iostream>
#include "./stb/stb_image.h"
#include "./stb/stb_image_write.h"

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Image
{
public:
    void loadImage(const char *filename)
    {
        data = stbi_load(filename, &m_width, &m_height, &m_channels, 3);
        if (data == nullptr)
        {
            std::cout << "Failed to load tiger image\n";
            return;
        }
    }

    void flip(int dir)
    {
        for (unsigned char *p = data; p != data + 300 * m_width * m_channels; p += m_channels)
        {
            *p = (uint8_t)0;
            *(p + 1) = (uint8_t)255;
            *(p + 2) = (uint8_t)0;
        }
    }

    void saveImage(const char *filename)
    {
        stbi_write_jpg("tiger-copy.jpg", m_width, m_height, m_channels, data, 100);
    }

    void convertTo2D()
    {
        uint32_t size = m_height * m_width * m_channels;
        for (unsigned char *p = data; *p <= size; *p += 3)
        {
            RGB color;
            std::vector<RGB> row;
            for (int i = 0; i < (m_width * m_channels); i++)
            {
                color.r = *p;
                color.g = *(p + 1);
                color.b = *(p + 2);
                row.emplace_back(color);
            }
            m_imageIn2D.emplace_back(row);
        }
    }

    void free()
    {
        stbi_image_free(data);
    }

private:
    unsigned char *data;
    int m_width;
    int m_channels;
    int m_height;
    std::string m_filename;
    std::vector<std::vector<RGB>> m_imageIn2D;
};

void flip(Image *img, int dir)
{
}

int main()
{
    Image img;
    img.loadImage("./images/tiger.jpg");
    img.flip(0);
    img.saveImage("tiger-copy.jpg");
    img.free();
    return 0;
}
