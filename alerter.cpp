#include "alerter.h"

class IAlerter {
public:
    virtual void alert() = 0;
};

// EmailAlert
class EmailAlert : public IAlerter {
public:
    void alert() override;

    bool emailSent = false; 
};

// LEDAlert 
class LEDAlert : public IAlerter {
public:
    void alert() override;

    bool ledGlows = false; 
};
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





