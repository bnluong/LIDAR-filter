#include "../include/median-filter.hpp"

lidar_filter::MedianFilter::MedianFilter(int d) :
    previousScanNum(d) {}

std::vector<double>& lidar_filter::MedianFilter::update(std::vector<double> &currentScan) {
    int n = currentScan.size();
    previousScans.push_back(currentScan);
    return currentScan;
}