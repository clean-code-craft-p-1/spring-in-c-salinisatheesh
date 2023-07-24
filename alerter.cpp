#include "alerter.h"

// Define call counters for emailAlerter and ledAlerter
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