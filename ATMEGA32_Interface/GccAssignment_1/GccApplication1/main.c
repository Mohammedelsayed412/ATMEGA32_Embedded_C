/*
 * GccApplication1.c
 *
 * Created: 12-Apr-21 9:07:40 PM
 * Author : AG
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
    unsigned int ch[]={0X00,0X01,0X02,0X03,0X04,0X05,0X06,0X07,0X10,0X11};
    unsigned int i = 0;
    unsigned int j = 0;
    DDRA = 0XFF;
    DDRB = 0XFF;
	
    while (1) 
    {	
		PORTA = 0X04;
		PORTB = ch[i];
		_delay_ms(30);
		PORTA = 0X08;
		PORTB = ch[j];
		_delay_ms(30);
		if (PINC == 0x00)
		{
			_delay_ms(200);
			
			i++;
			if (i == 10)
			{
				i=0;
				j++;
			}
			if (j == 10)
			{
				j = 0;
			}
			
		}
    }
}

