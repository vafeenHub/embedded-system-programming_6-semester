include config.h

OBJCOPY=avr-objcopy
CC=avr-gcc

ifeq ($(findstring B, ${POWER}), B)
	PORT_POWER=PORTB
	DDR_POWER=DDRB
else
	ifeq ($(findstring C, ${POWER}), C)
		PORT_POWER=PORTC
		DDR_POWER=DDRC
	else
		PORT_POWER=PORTD
		DDR_POWER=DDRD
	endif
endif

ifeq ($(findstring B, ${REVERSE}), B)
	PORT_REVERSE=PORTB
	DDR_REVERSE=DDRB
else
	ifeq ($(findstring C, ${REVERSE}), C)
		PORT_REVERSE=PORTC
		DDR_REVERSE=DDRC
	else
		PORT_REVERSE=PORTD
		DDR_REVERSE=DDRD
	endif
endif

ifeq ($(findstring B, ${STEPPER_PA}), B)
	PORT_STEPPER_PA=PORTB
	DDR_STEPPER_PA=DDRB
else
	ifeq ($(findstring C, ${STEPPER_PA}), C)
		PORT_STEPPER_PA=PORTC
		DDR_STEPPER_PA=DDRC
	else
		PORT_STEPPER_PA=PORTD
		DDR_STEPPER_PA=DDRD
	endif
endif

ifeq ($(findstring B, ${STEPPER_PB}), B)
	PORT_STEPPER_PB=PORTB
	DDR_STEPPER_PB=DDRB
else
	ifeq ($(findstring C, ${STEPPER_PB}), C)
		PORT_STEPPER_PB=PORTC
		DDR_STEPPER_PB=DDRC
	else
		PORT_STEPPER_PB=PORTD
		DDR_STEPPER_PB=DDRD
	endif
endif

ifeq ($(findstring B, ${STEPPER_NA}), B)
	PORT_STEPPER_NA=PORTB
	DDR_STEPPER_NA=DDRB
else
	ifeq ($(findstring C, ${STEPPER_NA}), C)
		PORT_STEPPER_NA=PORTC
		DDR_STEPPER_NA=DDRC
	else
		PORT_STEPPER_NA=PORTD
		DDR_STEPPER_NA=DDRD
	endif
endif

ifeq ($(findstring B, ${STEPPER_NB}), B)
	PORT_STEPPER_NB=PORTB
	DDR_STEPPER_NB=DDRB
else
	ifeq ($(findstring C, ${STEPPER_NB}), C)
		PORT_STEPPER_NB=PORTC
		DDR_STEPPER_NB=DDRC
	else
		PORT_STEPPER_NB=PORTD
		DDR_STEPPER_NB=DDRD	
	endif
endif

ifeq ($(findstring B, ${LED_A}), B)
	PORT_LED_A=PORTB
	DDR_LED_A=DDRB
else
	ifeq ($(findstring C, ${LED_A}), C)
		PORT_LED_A=PORTC
		DDR_LED_A=DDRC
	else
		PORT_LED_A=PORTD
		DDR_LED_A=DDRD
	endif
endif

ifeq ($(findstring B, ${LED_B}), B)
	PORT_LED_B=PORTB
	DDR_LED_B=DDRB
else
	ifeq ($(findstring C, ${LED_B}), C)
		PORT_LED_B=PORTC
		DDR_LED_B=DDRC
	else
		PORT_LED_B=PORTD
		DDR_LED_B=DDRD
	endif
endif

ifeq ($(findstring B, ${LED_C}), B)
	PORT_LED_C=PORTB
	DDR_LED_C=DDRB
else
	ifeq ($(findstring C, ${LED_C}), C)
		PORT_LED_C=PORTC
		DDR_LED_C=DDRC
	else
		PORT_LED_C=PORTD
		DDR_LED_C=DDRD
	endif
endif

ifeq ($(findstring B, ${LED_D}), B)
	PORT_LED_D=PORTB
	DDR_LED_D=DDRB
else
	ifeq ($(findstring C, ${LED_D}), C)
		PORT_LED_D=PORTC
		DDR_LED_D=DDRC
	else
		PORT_LED_D=PORTD
		DDR_LED_D=DDRD
	endif
endif

ifeq ($(findstring B, ${LED_E}), B)
	PORT_LED_E=PORTB
	DDR_LED_E=DDRB
else
	ifeq ($(findstring C, ${LED_E}), C)
		PORT_LED_E=PORTC
		DDR_LED_E=DDRC
	else
		PORT_LED_E=PORTD
		DDR_LED_E=DDRD
	endif
endif

ifeq ($(findstring B, ${LED_F}), B)
	PORT_LED_F=PORTB
	DDR_LED_F=DDRB
else
	ifeq ($(findstring C, ${LED_F}), C)
		PORT_LED_F=PORTC
		DDR_LED_F=DDRC
	else
		PORT_LED_F=PORTD
		DDR_LED_F=DDRD
	endif
endif

ifeq ($(findstring B, ${LED_G}), B)
	PORT_LED_G=PORTB
	DDR_LED_G=DDRB
else
	ifeq ($(findstring C, ${LED_G}), C)
		PORT_LED_G=PORTC
		DDR_LED_G=DDRC
	else
		PORT_LED_G=PORTD
		DDR_LED_G=DDRD
	endif
endif

ifeq ($(findstring B, ${SEG1}), B)
	PORT_SEG1=PORTB
	DDR_SEG1=DDRB
else
	ifeq ($(findstring C, ${SEG1}), C)
		PORT_SEG1=PORTC
		DDR_SEG1=DDRC
	else
		PORT_SEG1=PORTD
		DDR_SEG1=DDRD
	endif
endif

ifeq ($(findstring B, ${SEG2}), B)
	PORT_SEG2=PORTB
	DDR_SEG2=DDRB
else
	ifeq ($(findstring C, ${SEG2}), C)
		PORT_SEG2=PORTC
		DDR_SEG2=DDRC
	else
		PORT_SEG2=PORTD
		DDR_SEG2=DDRD
	endif
endif

ifeq ($(findstring B, ${SEG3}), B)
	PORT_SEG3=PORTB
	DDR_SEG3=DDRB
else
	ifeq ($(findstring C, ${SEG3}), C)
		PORT_SEG3=PORTC
		DDR_SEG3=DDRC
	else
		PORT_SEG3=PORTD
		DDR_SEG3=DDRD
	endif
endif

ifeq ($(findstring B, ${SEG4}), B)
	PORT_SEG4=PORTB
	DDR_SEG4=DDRB
else
	ifeq ($(findstring C, ${SEG4}), C)
		PORT_SEG4=PORTC
		DDR_SEG4=DDRC
	else
		PORT_SEG4=PORTD
		DDR_SEG4=DDRD
	endif
endif


CFLAGS_main= -std=c99 -Wall -g -Os -mmcu=${MAIN_MCU}\
		-DREVERSE=P${REVERSE} -DPORT_REVERSE=${PORT_REVERSE} -DDDR_REVERSE=${DDR_REVERSE}\
		-DPOWER=P${POWER} -DPORT_POWER=${PORT_POWER} -DDDR_POWER=${DDR_POWER}\
		-DSTEPPER_PA=P${STEPPER_PA} -DPORT_STEPPER_PA=${PORT_STEPPER_PA} -DDDR_STEPPER_PA=${DDR_STEPPER_PA}\
		-DSTEPPER_PB=P${STEPPER_PB} -DPORT_STEPPER_PB=${PORT_STEPPER_PB} -DDDR_STEPPER_PB=${DDR_STEPPER_PB}\
		-DSTEPPER_NA=P${STEPPER_NA} -DPORT_STEPPER_NA=${PORT_STEPPER_NA} -DDDR_STEPPER_NA=${DDR_STEPPER_NA}\
		-DSTEPPER_NB=P${STEPPER_NB} -DPORT_STEPPER_NB=${PORT_STEPPER_NB} -DDDR_STEPPER_NB=${DDR_STEPPER_NB}
		
TARGET_main=mcu_main
SRC_main=mcu_main.c


CFLAGS_second= -std=c99 -Wall -g -Os -mmcu=${SECOND_MCU}\
		-DLED_A=P${LED_A} -DPORT_LED_A=${PORT_LED_A} -DDDR_LED_A=${DDR_LED_A}\
		-DLED_B=P${LED_B} -DPORT_LED_B=${PORT_LED_B} -DDDR_LED_B=${DDR_LED_B}\
		-DLED_C=P${LED_C} -DPORT_LED_C=${PORT_LED_C} -DDDR_LED_C=${DDR_LED_C}\
		-DLED_D=P${LED_D} -DPORT_LED_D=${PORT_LED_D} -DDDR_LED_D=${DDR_LED_D}\
		-DLED_E=P${LED_E} -DPORT_LED_E=${PORT_LED_E} -DDDR_LED_E=${DDR_LED_E}\
		-DLED_F=P${LED_F} -DPORT_LED_F=${PORT_LED_F} -DDDR_LED_F=${DDR_LED_F}\
		-DLED_G=P${LED_G} -DPORT_LED_G=${PORT_LED_G} -DDDR_LED_G=${DDR_LED_G}\
        -DSEG1=P${SEG1} -DPORT_SEG1=${PORT_SEG1} -DDDR_SEG1=${DDR_SEG1}\
        -DSEG2=P${SEG2} -DPORT_SEG2=${PORT_SEG2} -DDDR_SEG2=${DDR_SEG2}\
        -DSEG3=P${SEG3} -DPORT_SEG3=${PORT_SEG3} -DDDR_SEG3=${DDR_SEG3}\
        -DSEG4=P${SEG4} -DPORT_SEG4=${PORT_SEG4} -DDDR_SEG4=${DDR_SEG4}\
		
		
TARGET_second=mcu_assist
SRC_second=mcu_assist.c

all:
	${CC} ${CFLAGS_main} -o ${TARGET_main}.bin ${SRC_main}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET_main}.bin ${TARGET_main}.hex

	${CC} ${CFLAGS_second} -o ${TARGET_second}.bin ${SRC_second}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET_second}.bin ${TARGET_second}.hex
