#include "stopwatch.h"

void LED_Mode_CountUp(void)
{
    PORTD |= (1 << PD4);
    PORTD &= ~(1 << PD5);
}

void LED_Mode_CountDown(void)
{
    PORTD |= (1 << PD5);
    PORTD &= ~(1 << PD4);
}
