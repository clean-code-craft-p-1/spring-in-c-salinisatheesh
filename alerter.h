#ifndef ALERTER_H_
#define ALERTER_H_

typedef void (*alerter_funcptr)(void);

void emailAlerter(void);
void ledAlerter(void);

#endif // ALERTER_H

