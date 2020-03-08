/** 
 * Author: Bao Luong
 * Description: A median filter extends from the base class filter
 */

#ifndef MEDIAN_FILTER_HPP
#define MEDIAN_FILTER_HPP

#include "filter.hpp"

namespace lidar_filter {
    class MedianFilter : Filter {
        int previousScanNum;
        std::vector<std::vector<double>> previousScans;
    public:
        MedianFilter(int d);
        virtual std::vector<double>& update(std::vector<double> &currentScan);
    };
}

#endif /* !MEDIAN_FILTER_HPP */