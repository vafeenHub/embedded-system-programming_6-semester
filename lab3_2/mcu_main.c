#define F_CPU 12000000UL
#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <util/setbaud.h>

const int delay_time[5] = {2000, 1000, 500, 300, 100};
volatile int current_speed = 0;
volatile bool reverse_flag = false;
volatile bool power_flag = false;

void delay()
{
    switch(current_speed)
    {
        case 0: _delay_ms(delay_time[0]); break;
        case 1: _delay_ms(delay_time[1]); break;
        case 2: _delay_ms(delay_time[2]); break;
        case 3: _delay_ms(delay_time[3]); break;
        case 4: _delay_ms(delay_time[4]); break;
    }
}

void uart_send(char c)
{
    UDR = c;
}

void uart_puts(char *s)
{
    while (*s)
    {
        uart_send(*s++);
    }
}

void StepForward()
{
    if(!reverse_flag && power_flag)
    {
        PORT_STEPPER_PA |= (1 << STEPPER_PA);
        delay();
        PORT_STEPPER_PA &= ~(1 << STEPPER_PA);
        if(!reverse_flag && power_flag)
        {
            PORT_STEPPER_PB |= ( 1 << STEPPER_PB);
            delay();
            PORT_STEPPER_PB &= ~(1 << STEPPER_PB);
            if(!reverse_flag && power_flag)
            {
                PORT_STEPPER_NA |= (1 << STEPPER_NA);
                delay();
                PORT_STEPPER_NA &= ~(1 << STEPPER_NA);
                if(!reverse_flag && power_flag)
                {
                    PORT_STEPPER_NB |= (1 << STEPPER_NB);
                    delay();
                    PORT_STEPPER_NB &= ~(1 << STEPPER_NB);
                }
            }
        }
    }
}
void StepBackward()
{  
    if(reverse_flag && power_flag)
    {
        PORT_STEPPER_NB |= (1 << STEPPER_NB);
        delay();
        PORT_STEPPER_NB &= ~(1 << STEPPER_NB);
        if(reverse_flag && power_flag)
        {
            PORT_STEPPER_NA |= (1 << STEPPER_NA);
            delay();
            PORT_STEPPER_NA &= ~(1 << STEPPER_NA);
            if(reverse_flag && power_flag)
            {
                PORT_STEPPER_PB |= (1 << STEPPER_PB);
                delay();
                PORT_STEPPER_PB &= ~(1 << STEPPER_PB);
                if(reverse_flag && power_flag)
                {
                    PORT_STEPPER_PA |= (1 << STEPPER_PA);
                    delay();
                    PORT_STEPPER_PA &= ~(1 << STEPPER_PA);
                }
            }
        }
    }
}

ISR(USART_RXC_vect)
{
    char input = UDR;
    //uart_send(input);
    switch(input)
    {
        case 's':
            if(!power_flag)
            {
                power_flag = true; 
                uart_send(current_speed + '0');
                PORT_POWER |= (1 << POWER);
                if(reverse_flag)
                {
                    PORT_REVERSE |= (1 << REVERSE);
                    //uart_puts("REV" + (current_speed + '0'));
                }
                else
                {
                    PORT_REVERSE &= ~(1 << REVERSE);
                    //uart_puts("F0R" + (current_speed + '0'));
                }
            }
            break;
        case 'f': 
            if(power_flag)
            {
                power_flag = false;
                uart_send('f');
                PORT_POWER &= ~(1 << POWER);
                PORT_REVERSE &= ~(1 << REVERSE);
            }
            break;
        case 'r': 
            if(power_flag)
            {
                reverse_flag = !reverse_flag;
                if(reverse_flag)
                    PORT_REVERSE |= (1 << REVERSE);
                else
                    PORT_REVERSE &= ~(1 << REVERSE);
            }
            break;
        case '+': 
            if (power_flag)
            {
                current_speed = (current_speed + 1) < 5 ? current_speed + 1 : 4; 
                uart_send(current_speed + '0');
            }
            break;
        case '-': 
            if (power_flag)
            {
                current_speed = (current_speed - 1) > 0 ? current_speed - 1 : 0; 
                uart_send(current_speed + '0');
            }
            break;
        default:
            break;
    }
}


int main()
{
    DDR_POWER |= (1 << POWER);
    PORT_POWER &= ~(1 << POWER);

    DDR_REVERSE |= (1 << REVERSE);
    PORT_REVERSE &= ~(1 << REVERSE);
    
    DDR_STEPPER_PA |= (1 << STEPPER_PA);
    PORT_STEPPER_PA &= ~(1 << STEPPER_PA);

    DDR_STEPPER_PB |= (1 << STEPPER_PB);
    PORT_STEPPER_PB &= ~(1 << STEPPER_PB);

    DDR_STEPPER_NA |= (1 << STEPPER_NA);
    PORT_STEPPER_NA &= ~(1 << STEPPER_NA);

    DDR_STEPPER_NB |= (1 << STEPPER_NB);
    PORT_STEPPER_NB &= ~(1 << STEPPER_NB);
    
    UBRRL = UBRRL_VALUE;
    UBRRH = UBRRH_VALUE;
	UCSRB = (1 << TXEN) | (1 << RXEN) | (1 << RXCIE);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

    sei(); 

    while (1)
    {
       
        while(power_flag)
        {
            if(reverse_flag)
                StepBackward();
            else
                StepForward();     
        }
    }
}
