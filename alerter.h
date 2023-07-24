#ifndef ALERTER_H
#define ALERTER_H

typedef void (*alerter_funcptr)(void);

void emailAlerter(void);
void ledAlerter(void);

void check_and_alert(const float maxThreshold, alerter_funcptr* alerters, struct Stats computedStats);

#endif // ALERTER_H
