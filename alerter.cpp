 #include "alerter.h"

void EmailAlert::Alert() {
    emailSent = true;
}

void LEDAlert::Alert() {
    ledGlows = true;
}

StatsAlerter::StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters)
    : maxThreshold_(maxThreshold), alerters_(alerters) {}

void StatsAlerter::checkAndAlert(const std::vector<float>& numberset) {
    Stats computedStats = Statistics::ComputeStatistics(numberset);
    if (computedStats.max > maxThreshold_) {
        for (auto alerter : alerters_) {
            alerter->Alert();
        }
    }
}
