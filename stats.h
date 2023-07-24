
#ifndef STATS_H
#define STATS_H

struct Stats {
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numbers, int length);
void check_and_alert(float maxThreshold, alerter_funcptr* alerters, struct Stats computedStats);

#endif // STATS_H
