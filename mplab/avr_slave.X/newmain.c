#define F_CPU 8000000UL
#include <avr/io.h>
#include<util/delay.h>
void TRANSMIT_CHAR(char a);
int main(void)
{
	DDRD=0xF2;
	UCSRA=0x00;
	UCSRB=0x18;
	UCSRC=0x86;
	UBRRL=51;
	char a;
	DDRC=~0;
	DDRB=1<<6;

	SPCR=1<<SPE|1<<CPHA|1<<CPOL;
	//SPSR=1<<SPIF;
	while(1)
	{
		SPDR=0x00;
        
        SPDR='A';
		while(!(SPSR & (1<<SPIF)));
		a=SPDR;
		TRANSMIT_CHAR(a);
		//SPSR=1<<SPIF; //1
	}
}

void TRANSMIT_CHAR(char a)
{
	UDR=a;
	while((UCSRA&0x40)==0);
	UCSRA=0x40;
}