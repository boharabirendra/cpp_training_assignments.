#ifndef IMAGE
#define IMAGE

#include <vector>
#include "../types/structs.h"

class Image
{
public:
    unsigned char *load(const char *);
    void save(const std::vector<std::vector<RGB>> &, const char *);
    std::vector<std::vector<RGB>> convertTo2D(const unsigned char *);
    ~Image()
    {
        if (imageData == nullptr)
            return;
        delete[] imageData;
    }

private:
    int width, height, channels;
    unsigned char *imageData = nullptr;
};

#endif