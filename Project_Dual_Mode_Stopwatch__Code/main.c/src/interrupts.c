#include "stopwatch.h"

ISR(TIMER1_COMPA_vect)
{
    if (resume_Y)
    {
        if (count_up_Y)
        {
            PORTD &= ~(1 << PD0);  // Buzzer off
            seconds_Y++;
            if (seconds_Y == 60)
            {
                seconds_Y = 0;
                minutes_Y++;
            }
            if (minutes_Y == 60)
            {
                hours_Y++;
                minutes_Y = 0;
            }
        }
        else
        {
            if (!hours_Y && !minutes_Y && !seconds_Y)
            {
                PORTD |= (1 << PD0);  // Buzzer on
            }
            else
            {
                PORTD &= ~(1 << PD0);  // Buzzer off
                seconds_Y--;
                if (seconds_Y == 0xFF)
                {
                    seconds_Y = 59;
                    minutes_Y--;
                }
                if (minutes_Y == 0xFF)
                {
                    hours_Y--;
                    minutes_Y = 59;
                }
            }
        }
    }
}

ISR(INT0_vect)
{
    seconds_Y = 0;
    minutes_Y = 0;
    hours_Y = 0;
    count_up_Y = 1;
    PORTD |= (1 << PD4);  // Set mode LED count up
    PORTD &= ~(1 << PD5); // Clear mode LED count down
    PORTD &= ~(1 << PD0); // Turn off buzzer
}

ISR(INT1_vect)
{
    if (resume_Y)
    {
        TCCR1B &= ~(1 << CS12); // Stop timer
        stopped_Y = 1;
        resume_Y = 0;
    }
}

ISR(INT2_vect)
{
    if (stopped_Y)
    {
        TCCR1B |= (1 << CS12);  // Start timer
        stopped_Y = 0;
        resume_Y = 1;
    }
}
