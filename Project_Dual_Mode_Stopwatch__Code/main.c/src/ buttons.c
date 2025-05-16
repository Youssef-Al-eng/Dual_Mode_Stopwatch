#include "stopwatch.h"
#include <avr/io.h>

void Buttons_Handler(void)
{
    if (stopped_Y)
    {
        // Hour decrement
        if (!(PINB & (1 << PB0)))
        {
            if (hours_Y != 0 && !hour_dec_flag_Y)
            {
                hours_Y--;
                hour_dec_flag_Y = 1;
            }
        }
        // Hour increment
        else if (!(PINB & (1 << PB1)))
        {
            if (hours_Y != 99 && !hour_inc_flag_Y)
            {
                hours_Y++;
                hour_inc_flag_Y = 1;
            }
        }
        else
        {
            hour_dec_flag_Y = 0;
            hour_inc_flag_Y = 0;
        }

        // Minute decrement
        if (!(PINB & (1 << PB3)))
        {
            if (minutes_Y != 0 && !min_dec_flag_Y)
            {
                minutes_Y--;
                min_dec_flag_Y = 1;
            }
        }
        // Minute increment
        else if (!(PINB & (1 << PB4)))
        {
            if (!min_inc_flag_Y)
            {
                minutes_Y++;
                if (minutes_Y == 60)
                {
                    hours_Y++;
                    minutes_Y = 0;
                }
                min_inc_flag_Y = 1;
            }
        }
        else
        {
            min_dec_flag_Y = 0;
            min_inc_flag_Y = 0;
        }

        // Second decrement
        if (!(PINB & (1 << PB5)))
        {
            if (seconds_Y != 0 && !sec_dec_flag_Y)
            {
                seconds_Y--;
                sec_dec_flag_Y = 1;
            }
        }
        // Second increment
        else if (!(PINB & (1 << PB6)))
        {
            if (!sec_inc_flag_Y)
            {
                seconds_Y++;
                if (seconds_Y == 60)
                {
                    minutes_Y++;
                    seconds_Y = 0;
                }
                sec_inc_flag_Y = 1;
            }
        }
        else
        {
            sec_dec_flag_Y = 0;
            sec_inc_flag_Y = 0;
        }

        // Toggle mode button
        if (!(PINB & (1 << PB7)))
        {
            if (!toggle_mode_flag_Y)
            {
                if (count_up_Y)
                {
                    count_up_Y = 0;
                    PORTD |= (1 << PD5);
                    PORTD &= ~(1 << PD4);
                }
                else
                {
                    count_up_Y = 1;
                    PORTD |= (1 << PD4);
                    PORTD &= ~(1 << PD5);
                }
                toggle_mode_flag_Y = 1;
            }
        }
        else
        {
            toggle_mode_flag_Y = 0;
        }
    }
}
