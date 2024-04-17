#define START_CONDITION 0x08
#define SLA_W_TRANSMITTED_ACK 0x18
#define DATA_TRANSMITTED_ACK 0x28

void TWI_master_init(void);
void TWI_master_start(void);
void TWI_master_trasnmit_slave_address(unsigned char, unsigned char);
void TWI_master_transmit_slave_data(unsigned char);
void TWI_master_stop(void);