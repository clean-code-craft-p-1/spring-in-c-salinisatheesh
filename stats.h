#ifndef STATS_H
#define STATS_H

struct Stats {
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numbers, int length);

#endif // STATS_H
