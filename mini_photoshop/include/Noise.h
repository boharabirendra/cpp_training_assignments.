#ifndef NOISE_H
#define NOISE_H

#include <vector>
#include "../types/structs.h"
#include "../include/Filter.h"

class Noise : public Filter
{
public:
    std::vector<std::vector<RGB>> apply(std::vector<std::vector<RGB>> &);
    Coordinate getRandomPixelLocation(int, int);
};

#endif