
#include "stats.h"
#include <algorithm>
#include <cmath>
using namespace Statistics;


Stats Statistics::ComputeStatistics(const std::vector<float>& inData)
{    Stats stats = {0.0f, 0.0f, 0.0f};

    if (length == 0) {
        return stats;
    }

    float sum = 0.0f;
    stats.min = stats.max = numbers[0];

    for (int i = 0; i < length; ++i) {
        sum += numbers[i];
        stats.min = std::min(stats.min, numbers[i]);
        stats.max = std::max(stats.max, numbers[i]);
    }

    stats.average = sum / static_cast<float>(length);
    return stats;
}
