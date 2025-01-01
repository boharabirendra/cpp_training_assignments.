#ifndef GRAYSCALE_h
#define GRAYSCALE_h

#include <vector>

#include "./Filter.h"
#include "../types/structs.h"

class GrayScale : public Filter
{
public:
    std::vector<std::vector<RGB>> apply(std::vector<std::vector<RGB>> &) override;
};

#endif