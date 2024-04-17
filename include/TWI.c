
#include <avr/io.h>
#include "TWI.h"

void TWI_master_init(void) {
    TWBR = 72;
    TWSR &= ~(1 <<  TWPS1) & ~(1 << TWPS0);
    DDRC &= ~(1 << DDC4) & ~(1 << DDC5);
    PORTC |= (1 << PORTB4) | (1 << PORTB5);
}

void TWI_master_start(void) {
    TWCR |= (1 << TWEN) | (1 << TWSTA) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
    while ((TWSR & 0xF8) != START_CONDITION);
}

void TWI_master_trasnmit_slave_address(unsigned char slave_address, unsigned char mode) {
    TWDR = (slave_address << 1) | mode;
    TWCR &= ~(1 << TWSTA);
    TWCR |= (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
    while ((TWSR & 0xF8) != SLA_W_TRANSMITTED_ACK);
}

void TWI_master_transmit_slave_data(unsigned char data) {
    TWDR = data;
    TWCR |= (1 << TWEN) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
    while ((TWSR & 0xF8) != DATA_TRANSMITTED_ACK);
}

void TWI_master_stop(void) {
    TWCR |= (1 << TWEN) | (1 << TWSTO) | (1 << TWINT);
    while (TWCR & (1 << TWSTO));
}