
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char PORTA_count = 0;
unsigned char temp;


void switchs_config (void)
{  DDRA = DDRA & 0x00;   
	PORTA = PORTA | 0xFF;
}


void LEDs_config (void)
{  DDRB = 0xFF;  
	PORTB = 0x00; 
}


void port_init (void)
{  switchs_config();
	LEDs_config();
}


void init_devices (void)
{  cli(); 
	port_init();
	sei(); 
}


int main(void)
{
	init_devices();
	
	PORTB = 0x00;
	
	while(1)
	{
		
		temp = PINA;             
		if((temp & 0x01) == 0x00)
		{       
		    PORTB = 0x01;   
			if((temp & 0x02) == 0x00)
			{   
				      PORTB = 0x02;  
			}
			if((temp & 0x04) == 0x00)
			{   
				      PORTB = 0x04;  
			}
			if((temp & 0x08) == 0x00)
			{   
				      PORTB = 0x08;  
			}
			if((temp & 0x10) == 0x00)
			{   
				      PORTB = 0x10;   
			}
			if((temp & 0x20) == 0x00)
			{   
				      PORTB = 0x20;   
			}
			if((temp & 0x40) == 0x00)
			{   
				      PORTB = 0x40;   
			}
			if((temp & 0x80) == 0x00)
			{
				         PORTB = 0x80;   
			}
			else      
			 {
				PORTB = 0x00;
			}
			
		}
	}
}