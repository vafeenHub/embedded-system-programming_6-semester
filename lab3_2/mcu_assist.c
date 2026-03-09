#define F_CPU 12000000UL
#define BAUD 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD)) - 1)
#define MAX_SEGMENTS 4

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include <util/setbaud.h>

volatile char display_buffer[MAX_SEGMENTS] = {'S', 'P', '_', 'f'};

void print_0()
{
    PORT_LED_A |= (1<<LED_A);
    PORT_LED_B |= (1<<LED_B);
    PORT_LED_C |= (1<<LED_C);
    PORT_LED_D |= (1<<LED_D);
    PORT_LED_E |= (1<<LED_E);
    PORT_LED_F |= (1<<LED_F);
}

void print_1()
{
    PORT_LED_B |= (1<<LED_B);
    PORT_LED_C |= (1<<LED_C);
}

void print_2()
{
    PORT_LED_A |= (1<<LED_A);
    PORT_LED_B |= (1<<LED_B);
    PORT_LED_G |= (1<<LED_G);
    PORT_LED_D |= (1<<LED_D);
    PORT_LED_F |= (1<<LED_F);
}

void print_3()
{
    PORT_LED_A |= (1<<LED_A);
    PORT_LED_B |= (1<<LED_B);
    PORT_LED_C |= (1<<LED_C);
    PORT_LED_D |= (1<<LED_D);
    PORT_LED_G |= (1<<LED_G);
}

void print_4()
{
    PORT_LED_B |= (1<<LED_B);
    PORT_LED_C |= (1<<LED_C);
    PORT_LED_E |= (1<<LED_E);
    PORT_LED_G |= (1<<LED_G);
}

void print_5()
{
    PORT_LED_A |= (1<<LED_A);
    PORT_LED_C |= (1<<LED_C);
    PORT_LED_D |= (1<<LED_D);
    PORT_LED_E |= (1<<LED_E);
    PORT_LED_G |= (1<<LED_G);
}

void print_S()
{
    PORT_LED_A |= (1<<LED_A);
    PORT_LED_D |= (1<<LED_D);
    PORT_LED_E |= (1<<LED_E);
    PORT_LED_G |= (1<<LED_G);
    PORT_LED_C |= (1<<LED_C);
}

void print_T()
{
    PORT_LED_D |= (1<<LED_D);
    PORT_LED_E |= (1<<LED_E);
    PORT_LED_B |= (1<<LED_B);
    PORT_LED_G |= (1<<LED_G);
    PORT_LED_D |= (1<<LED_D);
}

void print_P()
{
    PORT_LED_A |= (1<<LED_A);
    PORT_LED_E |= (1<<LED_E);
    PORT_LED_F |= (1<<LED_F);
    PORT_LED_G |= (1<<LED_G);
    PORT_LED_B |= (1<<LED_B);
}

void print__()
{
    PORT_LED_D |= (1<<LED_D);
}

void clear()
{
    PORT_LED_A &= ~(1<<LED_A);
    PORT_LED_B &= ~(1<<LED_B);
    PORT_LED_C &= ~(1<<LED_C);
    PORT_LED_D &= ~(1<<LED_D);
    PORT_LED_E &= ~(1<<LED_E);
    PORT_LED_F &= ~(1<<LED_F);
    PORT_LED_G &= ~(1<<LED_G);

}

void activate_segment(volatile uint8_t segment)
{
    PORT_SEG1 |= (1 << SEG1);
    PORT_SEG2 |= (1 << SEG2);
    PORT_SEG3 |= (1 << SEG3);
    PORT_SEG4 |= (1 << SEG4);

    switch(segment)
    {
        case 0: PORT_SEG1 &= ~(1 << SEG1); break;
        case 1: PORT_SEG2 &= ~(1 << SEG2); break;
        case 2: PORT_SEG3 &= ~(1 << SEG3); break;
        case 3: PORT_SEG4 &= ~(1 << SEG4); break;
    }
}

void update_display(volatile char* display_buffer)
{        
    for (int seg = 0; seg < MAX_SEGMENTS; seg++)
    {
        clear();        
        activate_segment(seg);
        switch(seg)
        {
            case 0: print_S(); break;
            case 1: print_P(); break;
            case 2: print__(); break;
            case 3:
                clear();
                switch(display_buffer[seg])
                {
                    case '0': print_1(); break;
                    case '1': print_2(); break;
                    case '2': print_3(); break;
                    case '3': print_4(); break;
                    case '4': print_5(); break;
                    default:  print_0(); break;
                }
                break;
            default:
                clear();
        }
        
        _delay_ms(1);
        clear();
    }    
}


ISR(USART_RXC_vect)
{
    char c = UDR;
    display_buffer[3] = c;
    //update_display(display_buffer);
}

int main()
{
    DDR_LED_A |= (1<<LED_A);
    PORT_LED_A &= ~(1<<LED_A);

    DDR_LED_B |= (1<<LED_B);
    PORT_LED_B &= ~(1<<LED_B);

    DDR_LED_C |= (1<<LED_C);
    PORT_LED_C &= ~(1<<LED_C);

    DDR_LED_D |= (1<<LED_D);
    PORT_LED_D &= ~(1<<LED_D);

    DDR_LED_E |= (1<<LED_E);
    PORT_LED_E &= ~(1<<LED_E);

    DDR_LED_F |= (1<<LED_F);
    PORT_LED_F &= ~(1<<LED_F);

    DDR_LED_G |= (1<<LED_G);
    PORT_LED_G &= ~(1<<LED_G);

    DDR_SEG1 |= (1 << SEG1);
    PORT_SEG1 &= ~(1 << SEG1);
    DDR_SEG2 |= (1 << SEG2);
    PORT_SEG2 &= ~(1 << SEG2);
    DDR_SEG3 |= (1 << SEG3);
    PORT_SEG3 &= ~(1 << SEG3);
    DDR_SEG4 |= (1 << SEG4);
    PORT_SEG4 &= ~(1 << SEG4);


    UBRRL = UBRRL_VALUE;
    UBRRH = UBRRH_VALUE;
	UCSRB = (1 << TXEN) | (1 << RXEN) | (1 << RXCIE);
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

    sei(); 
    
    while(1)
    {
        update_display(display_buffer);
    }
}  
