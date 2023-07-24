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

void check_and_alert(const float maxThreshold, alerter_funcptr* alerters, struct Stats computedStats) {
    if (computedStats.max > maxThreshold) {
        for (int i = 0; i < 2; ++i) {
            alerters[i](); 
        }
    }
}
