#include "stopwatch.h"

void Buzzer_On(void)
{
    PORTD |= (1 << PD0);
}

void Buzzer_Off(void)
{
    PORTD &= ~(1 << PD0);
}
