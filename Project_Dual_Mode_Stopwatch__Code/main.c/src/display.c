#include "stopwatch.h"
#include <util/delay.h>

#define DISPLAY_DELAY 2

void DisplayTime(void)
{
    PORTA = (PORTA & 0xC0) | (1 << PA0);
    PORTC = (PORTC & 0xF0) | ((hours_Y / 10) & 0x0F);
    _delay_ms(DISPLAY_DELAY);

    PORTA = (PORTA & 0xC0) | (1 << PA1);
    PORTC = (PORTC & 0xF0) | ((hours_Y % 10) & 0x0F);
    _delay_ms(DISPLAY_DELAY);

    PORTA = (PORTA & 0xC0) | (1 << PA2);
    PORTC = (PORTC & 0xF0) | ((minutes_Y / 10) & 0x0F);
    _delay_ms(DISPLAY_DELAY);

    PORTA = (PORTA & 0xC0) | (1 << PA3);
    PORTC = (PORTC & 0xF0) | ((minutes_Y % 10) & 0x0F);
    _delay_ms(DISPLAY_DELAY);

    PORTA = (PORTA & 0xC0) | (1 << PA4);
    PORTC = (PORTC & 0xF0) | ((seconds_Y / 10) & 0x0F);
    _delay_ms(DISPLAY_DELAY);

    PORTA = (PORTA & 0xC0) | (1 << PA5);
    PORTC = (PORTC & 0xF0) | ((seconds_Y % 10) & 0x0F);
    _delay_ms(DISPLAY_DELAY);
}
