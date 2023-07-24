#include "stats.h"
#include "alerter.h" // Include the alerter.h header

#include "gtest/gtest.h"
#include <cmath>

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

// Tests...

TEST(Statistics, ReportsAverageMinMax) {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    EXPECT_LT(std::abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(std::abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(std::abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    auto computedStats = Statistics::ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
}

TEST(Alert, AlertsWhenMaxExceeds) {
    EmailAlert emailAlert;
    LEDAlert ledAlert;
    std::vector<IAlerter*> alerters = {&emailAlert, &ledAlert};

    const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(maxThreshold, alerters);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    EXPECT_TRUE(emailAlert.emailSent);
    EXPECT_TRUE(ledAlert.ledGlows);
}
