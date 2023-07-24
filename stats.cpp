#include "stats.h"
#include <algorithm>
#include <numeric>

Stats Statistics::ComputeStatistics(const std::vector<float>& numberset) {
    Stats result;

    if (numberset.empty()) {
        result.average = NAN;
        result.max = NAN;
        result.min = NAN;
        return result;
    }

    result.min = *std::min_element(numberset.begin(), numberset.end());
    result.max = *std::max_element(numberset.begin(), numberset.end());
    result.average = std::accumulate(numberset.begin(), numberset.end(), 0.0f) / numberset.size();

    return result;
}