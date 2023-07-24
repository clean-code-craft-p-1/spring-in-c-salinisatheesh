#ifndef STATS_H
#define STATS_H

#include <vector>

struct Stats {
    float average;
    float max;
    float min;
};

class Statistics {
public:
    static Stats ComputeStatistics(const std::vector<float>& numberset);
};

#endif // STATS_H
