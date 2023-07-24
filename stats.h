#include <stdio.h>
#include <vector>
struct Stats {
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numbers, int length);


