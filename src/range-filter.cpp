#include "../include/range-filter.hpp"

lidar_filter::RangeFilter::RangeFilter(double min, double max) :
    rangeMin(min), rangeMax(max) {}

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