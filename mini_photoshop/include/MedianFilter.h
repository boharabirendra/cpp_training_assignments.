#ifndef MEDIANFILTER_H
#define MEDIANFILTER_H

#include <vector>

#include "./Filter.h"
#include "../types/structs.h"

class MedianFilter : public Filter
{
public:
    uint8_t computeMedian(std::vector<uint8_t> &);
    std::vector<std::vector<RGB>> apply(std::vector<std::vector<RGB>> &) override;
    std::vector<RGB> getNeighbors(const std::vector<std::vector<RGB>> &, int, int);
};

#endif