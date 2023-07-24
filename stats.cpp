#include "stats.h"
#include "alerter.h"
// Define call counters for emailAlerter and ledAlerter
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

struct Stats compute_statistics(const float* numbers, int length) {
    Stats result;

    if (length == 0) {
        result.average = 0.0;
        result.max = 0.0;
        result.min = 0.0;
        return result;
    }

    result.min = numbers[0];
    result.max = numbers[0];
    float sum = numbers[0];

    for (int i = 1; i < length; ++i) {
        if (numbers[i] < result.min) {
            result.min = numbers[i];
        }
        if (numbers[i] > result.max) {
            result.max = numbers[i];
        }
        sum += numbers[i];
    }

    result.average = sum / static_cast<float>(length);

    return result;
}

void check_and_alert(const float maxThreshold, alerter_funcptr* alerters, struct Stats computedStats) {
    if (computedStats.max > maxThreshold) {
        for (int i = 0; i < 2; ++i) {
            alerters[i](); 
        }
    }
}