#include "stats.h"
#include "alerter.h"
#include "gtest/gtest.h"
#include <stdlib.h>
#include <math.h>

TEST(Statistics, ReportsAverageMinMax) {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    struct Stats computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    EXPECT_LT(abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(abs(computedStats.min - 1.5), epsilon);
}

TEST(Statistics, AverageNaNForEmpty) {
    Stats computedStats = compute_statistics(0, 0);
    // Test that the average, max, and min values are NaN for an empty array
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.max));
    EXPECT_TRUE(std::isnan(computedStats.min));
}

extern int emailAlertCallCount;
extern int ledAlertCallCount;

TEST(Alert, AlertsWhenMaxExceeds) {
    // create additional .c and .h files
    // containing functions called emailAlerter, ledAlerter
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    EXPECT_EQ(emailAlertCallCount, 1);
    EXPECT_EQ(ledAlertCallCount, 1);
}
