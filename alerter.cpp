#include "alerter.h"

// EmailAlert implementation
void EmailAlert::alert() {
    // Implementation to send an email alert
    // For the purpose of this example, we will just set a flag to indicate the alert
    emailSent = true;
}

// LEDAlert implementation
void LEDAlert::alert() {
    // Implementation to activate an LED alert
    // For the purpose of this example, we will just set a flag to indicate the alert
    ledGlows = true;
}

// StatsAlerter constructor
StatsAlerter::StatsAlerter(float maxThreshold, const std::vector<IAlerter*>& alerters)
    : maxThreshold(maxThreshold), alerters(alerters) {}

// Function to check input data and trigger alerts if needed
void StatsAlerter::checkAndAlert(const std::vector<float>& data) {
    if (data.empty())
        return;

    float max = data[0];

    // Find the maximum value in the input data
    for (float value : data) {
        if (value > max) {
            max = value;
        }
    }

    // Check if the maximum value exceeds the threshold
    if (max > maxThreshold) {
        // Trigger alerts by calling the alert() function on each IAlerter object
        for (IAlerter* alerter : alerters) {
            alerter->alert();
        }
    }
}

