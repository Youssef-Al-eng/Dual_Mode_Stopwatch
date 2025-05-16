#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <avr/io.h>
#include <avr/interrupt.h>

// Global Variables
extern volatile unsigned char count_up_Y;
extern volatile unsigned char seconds_Y;
extern volatile unsigned char minutes_Y;
extern volatile unsigned char hours_Y;

extern volatile unsigned char stopped_Y;
extern volatile unsigned char resume_Y;

extern volatile unsigned char hour_inc_flag_Y;
extern volatile unsigned char hour_dec_flag_Y;
extern volatile unsigned char min_inc_flag_Y;
extern volatile unsigned char min_dec_flag_Y;
extern volatile unsigned char sec_inc_flag_Y;
extern volatile unsigned char sec_dec_flag_Y;
extern volatile unsigned char toggle_mode_flag_Y;

// Initialization Functions
void TIMER1_CTC_INIT(void);
void DISPLAY_INIT(void);
void RESET_INIT(void);
void PAUSE_INIT(void);
void RESUME_INIT(void);
void NORMAL_BUTTONS_INIT(void);
void ALARM_INIT(void);
void COUNT_LEDS_INIT(void);

// Main display function
void DisplayTime(void);

#endif
