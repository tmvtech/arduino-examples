#include <avr/io.h>
#include <util/delay.h>

int main()
{
    // NanoV3.3_sch.pdf https://content.arduino.cc/assets/NanoV3.3_sch.pdf
    // LED is in D13 -> PB5
    // Set pin as output
    DDRB |= (1 << DDB5);
    while(1) 
    {
        // Turn on LED
        PORTB |= (1 << DDB5);
        // Wait
        _delay_ms(500);
        // Turn off LED
        PORTB &= ~(1 << DDB5);
        // Wait
        _delay_ms(1500);
    }
    return 0;
}
