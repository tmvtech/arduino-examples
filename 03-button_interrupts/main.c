#include <avr/io.h>
#include <avr/interrupt.h>

void init_btn()
{
    // Set pin 2 as input
    DDRD &= ~(1 << PD2);
    // Set pin 2 as pullup
    PORTD |= (1 << PD2);
    // when to trigger interrupt
    // none = on low, 0 = on change, 1 = on down, 1 & 0 = on up, 
    EICRA |= (1 << ISC01);
    // enable interrupts for int0
    EIMSK |= (1 << INT0);
    // enable global interrupts
}

// Interrupt service routine (ISR) for INT0
ISR(INT0_vect)
{
    // Flip pin state
    PORTB ^= (1 << PB5);
}

int main()
{
    // onboard led pin > output
    DDRB |= (1 << PB5);

    // init button
    init_btn();

    // enable global interrupts 
    sei();
    
    // loop forever
    while (1);
    return 0;
}