#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h> 
void buzzer_pin_config (void)
{  
	DDRC = DDRC | 0x08;   
	PORTC = PORTC & 0xF7; 
}
void port_init (void)
{
			   buzzer_pin_config(); 
} 
void buzzer_on (void) 
{
	unsigned char port_restore = 0; 
	port_restore = PINC;  
	port_restore = port_restore | 0x08; 
	PORTC = port_restore; } 
	void buzzer_off (void)
	   {  
			unsigned char port_restore = 0;
		    port_restore = PINC; 
			port_restore = port_restore & 0xF7;
		    PORTC = port_restore;
	   }    
	void init_devices (void)
	   {     
	     	cli(); //Clears the global interrupts 
	     	port_init();  sei(); //Enables the global interrupts
	   }
int main(void) //Main Function
		{ 
			 init_devices(); 
			 while(1)  
				{  
					buzzer_on();
					_delay_ms(1000); //delay  
					buzzer_off(); 
				    _delay_ms(1000); //delay 
				}
} 