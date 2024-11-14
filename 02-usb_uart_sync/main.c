#include <avr/io.h>
#include <util/delay.h>

// https://ww1.microchip.com/downloads/en/DeviceDoc/ATmega48A-PA-88A-PA-168A-PA-328-P-DS-DS40002061A.pdf

// CPU frequency
#define F_CPU 16000000UL
// Serial speed in bps, check page 199 of the pdf
#define BAUD 16 //115200

void uart_init() 
{
    UCSR0A |= (1 << U2X0); // Enable double speed
    UCSR0B |= (1 << RXEN0) | (1 << TXEN0); //Enable receiver and transmitter
    UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00); // 8-bit char size

    UBRR0 = BAUD;
}

void uart_sendchar(unsigned char data) 
{
    // Wait until the transmit buffer is empty
    while (!(UCSR0A & (1 << UDRE0)));

    // Put data into buffer, sends the data
    UDR0 = data;
}

void uart_sendstr(unsigned char* data)
{
    int i = 0;
    while (data[i] != '\0')
        uart_sendchar(data[i++]);
}

int main() 
{
    //Init Uart
    uart_init();

    while (1) 
    {
        // Send Hello
        uart_sendstr("Hello\n");

        // Wait
        _delay_ms(1000);
    }

    return 0;
}
