
#include <avr/io.h>
// #include "TWI.h"
#include "TWI.c"
#include <util/delay.h>

unsigned char slave_address = 0x0F;
unsigned char mode = 0;
unsigned char data = 'G';

void led_init(void) {
    DDRB |= (1 << DDB5);
    PORTB |= (1 << PORTB5);
} 

void led_blink(void) {
    for (unsigned char i = 0; i < 5; i++) {
        PORTB ^= (1 << PORTB5);
        _delay_ms(500);
    }
}

int main() {
    TWI_master_init();
    led_init();

    while (1) {
        led_blink();
        _delay_ms(1000);
        TWI_master_start();
        TWI_master_trasnmit_slave_address(slave_address, mode);
        TWI_master_transmit_slave_data(data);
        TWI_master_stop();
        _delay_ms(1000);
    }

    return 0;
}