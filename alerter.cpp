#include "alerter.h"

void EmailAlert::alert() {
    // Code to send email alert
    emailSent = true;
}

void LEDAlert::alert() {
    // Code to make LED glow
    ledGlows = true;
}

StatsAlerter::StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters)
    : maxThreshold_(maxThreshold), alerters_(alerters) {}

void StatsAlerter::checkAndAlert(const std::vector<float>& numberset) {
    Stats computedStats = compute_statistics(numberset.data(), numberset.size());
    if (computedStats.max > maxThreshold_) {
        for (auto alerter : alerters_) {
            alerter->alert();
        }
    }
}






