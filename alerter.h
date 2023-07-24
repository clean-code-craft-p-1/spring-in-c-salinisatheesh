#ifndef ALERTER_H
#define ALERTER_H

typedef void (*alerter_funcptr)(void);

void emailAlerter(void);
void ledAlerter(void);

#endif // ALERTER_H
