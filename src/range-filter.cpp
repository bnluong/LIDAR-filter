/** 
 * Author: Bao Luong
 */

#include "../include/range-filter.hpp"

lidar_filter::RangeFilter::RangeFilter(double min, double max) :
    rangeMin(min), rangeMax(max) {}

/**
 * Filter noise in data using range filter
 *
 * @param currentScan current scan of data
 * @return updated scan with each entry is cropped to the min_range or max_range respectively
 */
std::vector<double>& lidar_filter::RangeFilter::update(std::vector<double> &currentScan) {
    int n = currentScan.size();

    for(int i = 0; i < n; i++) {
        if(currentScan[i] < rangeMin)
            currentScan[i] = rangeMin;
        if(currentScan[i] > rangeMax)
            currentScan[i] = rangeMax;
    }

    return currentScan;
}