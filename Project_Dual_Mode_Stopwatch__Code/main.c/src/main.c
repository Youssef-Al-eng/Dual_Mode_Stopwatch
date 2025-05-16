#include "stopwatch.h"

volatile unsigned char count_up_Y = 1;
volatile unsigned char seconds_Y = 0;
volatile unsigned char minutes_Y = 0;
volatile unsigned char hours_Y = 0;

volatile unsigned char stopped_Y = 0;
volatile unsigned char resume_Y = 1;

volatile unsigned char hour_inc_flag_Y = 0;
volatile unsigned char hour_dec_flag_Y = 0;
volatile unsigned char min_inc_flag_Y = 0;
volatile unsigned char min_dec_flag_Y = 0;
volatile unsigned char sec_inc_flag_Y = 0;
volatile unsigned char sec_dec_flag_Y = 0;
volatile unsigned char toggle_mode_flag_Y = 0;

void TIMER1_CTC_INIT(void)
{
    TCCR1A = (1 << FOC1A);
    ICR1 = 62499;
    TCCR1B = (1 << CS12) | (1 << WGM12) | (1 << WGM13);
    TIMSK |= (1 << OCIE1A);
    TCNT1 = 0;
}

void DISPLAY_INIT(void)
{
    DDRA |= 0x3F;
    DDRC |= 0x0F;
    PORTA &= 0xC0;
}

void RESET_INIT(void)
{
    MCUCR |= (1 << ISC01);
    GICR |= (1 << INT0);
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);
}

void PAUSE_INIT(void)
{
    MCUCR |= (1 << ISC10) | (1 << ISC11);
    GICR |= (1 << INT1);
    DDRD &= ~(1 << PD3);
}

void RESUME_INIT(void)
{
    MCUCR &= ~(1 << ISC2);
    GICR |= (1 << INT2);
    DDRB &= ~(1 << PB2);
    PORTB |= (1 << PB2);
}

void NORMAL_BUTTONS_INIT(void)
{
    DDRB &= 0x04;
    PORTB |= 0xFB;
}

void ALARM_INIT(void)
{
    DDRD |= (1 << PD0);
    PORTD &= ~(1 << PD0);
}

void COUNT_LEDS_INIT(void)
{
    DDRD |= 0x30;
    PORTD |= (1 << PD4);
    PORTD &= ~(1 << PD5);
}

int main(void)
{
    TIMER1_CTC_INIT();
    DISPLAY_INIT();
    RESET_INIT();
    PAUSE_INIT();
    RESUME_INIT();
    NORMAL_BUTTONS_INIT();
    COUNT_LEDS_INIT();
    ALARM_INIT();
    sei();

    while (1)
    {
        DisplayTime();
        Buttons_Handler();
    }
    return 0;
}
