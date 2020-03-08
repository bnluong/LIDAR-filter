/** 
 * Author: Bao Luong
 */

#include "../include/median-filter.hpp"
#include "algorithm"

lidar_filter::MedianFilter::MedianFilter(int d) :
    previousScanNum(d) {}

/**
 * Filter noise in data using temporal median filter algorithm
 *
* @param currentScan current scan of data
 * @return updated scan with each entry is the median of previous d scans
 */
std::vector<double>& lidar_filter::MedianFilter::update(std::vector<double> &currentScan) {
    int n = currentScan.size();
    
    if(previousScans.empty()) {
        previousScans.push_back(currentScan);
        return currentScan;
    }

    previousScans.push_back(currentScan);

    for(int i = 0; i < n; i++) {
        std::vector<double> window;
        for(int j = 0; j < previousScans.size(); j++) 
            window.push_back(previousScans[j][i]);
        std::sort(window.begin(), window.end());
        if(window.size() % 2 == 0) {
            double median = (window[window.size() / 2] + window[window.size() / 2 - 1]) / 2;
            currentScan[i] = median;
        } else {
            double median = window[window.size() / 2];
            currentScan[i] = median;
        }
    }

    if(previousScans.size() > previousScanNum)
        previousScans.erase(previousScans.begin());

    return currentScan;
}