#include "alerter.h"

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter(void) {
    // Implementation of emailAlerter (can be left empty for testing purposes)
    emailAlertCallCount++;
}

void ledAlerter(void) {
    // Implementation of ledAlerter (can be left empty for testing purposes)
    ledAlertCallCount++;
}

StatsAlerter::StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters)
    : maxThreshold_(maxThreshold), alerters_(alerters) {}

void StatsAlerter::checkAndAlert(const std::vector<float>& numberset) {
    Stats computedStats = compute_statistics(numberset.data(), numberset.size());
    if (computedStats.max > maxThreshold_) {
        for (auto alerter : alerters_) {
            alerter();
        }
    }
}






