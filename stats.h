#ifndef STATS_H_
#define STATS_H_

struct Stats {
    float average;
    float max;
    float min;
};

struct Stats compute_statistics(const float* numberset, int setlength);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

#endif // STATS_H