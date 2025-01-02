#include "../types/enums.h"
#include "../include/Noise.h"
#include "../include/GrayScale.h"
#include "../include/MedianFilter.h"
#include "../include/FilterFactory.h"

Filter *FilterFactory::getFilter(int opt)
{
    Filter *filter;

    switch (static_cast<FILTERTYPES>(opt))
    {
    case FILTERTYPES::MEDIAN:
        filter = new MedianFilter();
        break;
    case FILTERTYPES::GRAYSCALE:
        filter = new GrayScale();
        break;
    case FILTERTYPES::ADDNOISE:
        filter = new Noise();
        break;
    default:
        break;
    }

    return filter;
}