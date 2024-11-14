#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
// CPU Frequency (Arduino is usually 16MHz but can also be 8MHz)
#define F_CPU 16000000UL
#endif

// Initialize and start the timer 0
void init_timer0()
{
    TCCR0A = 0; // normal operating mode
    // enable CTC
    TCCR0A |= (1 << WGM01);
    // set prescaler to 64 (page 117)
    TCCR0B |= (1 << CS01) | (1 << CS00);
    // enable output compare A
    TIMSK0 |= (1 << OCIE0A);
    // 1 interrupt per ms
    // used the formula given at 
    // https://www.tmvtech.com/baremetal-arduino-timers#calc
    OCR0A = 250;
}

// Stores how much ms since the arduino is on
volatile uint16_t t0_millis = 0;
// Interrupt service routine (ISR) for Timer0
ISR(TIMER0_COMPA_vect)
{
    t0_millis++;
}

int main()
{
    // onboard led pin as output
    DDRB |= (1 << PB5);

    // initialize timer 0
    init_timer0();

    // Enable global interrupts
    sei();

    // loop forever
    while (1)
    {
        // when one second has elapsed
        if (t0_millis >= 1000)
        {
            // flip led state
            PORTB ^= (1 << PB5);
            // reset count
            t0_millis = 0; 
        }
    }
    return 0;
}