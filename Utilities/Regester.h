#ifndef REGISTER_H
#define REGISTER_H
	
// Port A Registers
#define PortA *((volatile uint8_t*) (0x3B))
#define DDRA *((volatile uint8_t*) (0x3A))
#define PinA *((volatile uint8_t*) (0x39))	

// Port B Registers
#define PortB *((volatile uint8_t*) (0x38))
#define DDRB *((volatile uint8_t*) (0x37))
#define PinB *((volatile uint8_t*) (0x36))

// Port D Registers
#define PortD *((volatile uint8_t*) (0x32))
#define DDRD *((volatile uint8_t*) (0x31))
#define PinD *((volatile uint8_t*) (0x30))

// Timer 0
#define T0_FLAG *((volatile uint8_t*) (0x58))		// TIFR – Timer/Counter Interrupt Flag Register
#define T0_CONTROL *((volatile uint8_t*) (0x53))	// TCCR0 – Timer/Counter Control Register
#define T0_COUNTER *((volatile uint8_t*) (0x52))	// TCNT0 – Timer/Counter Register

// Interrupt
#define SREG *((volatile uint8_t*) (0x5F))		// Status Register
#define GICR *((volatile uint8_t*) (0x5B))		// General Interrupt Control Register – GICR
#define GIFR *((volatile uint8_t*) (0x5A))		// General Interrupt Flag Register – GIFR
#define MCUCR *((volatile uint8_t*) (0x55))		// MCU Control Register –MCUCR


#endif /* REGISTER_H */