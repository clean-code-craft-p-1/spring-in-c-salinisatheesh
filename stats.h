#include <stdio.h>
#include <vector.h>
struct Stats {
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numbers, int length);


