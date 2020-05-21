.INCLUDE "M32DEF.INC"
.ORG 0
   JMP MAIN
.ORG 0X02
   JMP INT0_TRIG

MAIN:
	LDI R20,0X02
	OUT MCUCR,R20
	LDI R20,1<<INT0
	OUT GICR,R20
	SEI
	LDI R20,0X0F
	OUT DDRC,R20
	LDI R20,0X0F
	OUT PORTC,R20
HERE:JMP HERE

INT0_TRIG:
	//CALL DELAY_20MS
	LDI R20,0B01111111;
	OUT PORTC,R21
	NOP
	IN R21,0X0F
	ANDI R21,0B0111111
	OUT PORTC,R21
	NOP
	IN R21,PINC
	ANDI R21,0X0F
	BRNE COL1
	LDI R21, 0B1011111
	OUT PORTC,R21
	NOP
	IN R21,PINC
	ANDI R21,0X0F
	BRNE COL2
	LDI R21,0B11011111
	OUT PORTC,R21
	NOP
	IN R21,PINC
	ANDI R21,0X0F
	CPI R21,0X0F
	BRNE COL3
	LDI R21,0B11101111
	OUT PORTC,R21
	NOP
	IN R21,PINC
	ANDI R21,0X0F
	CPI R21,0X0F
	BRNE COL4
COL1:LDI R30,LOW(KL0DE0<<1)
     LDI R31,HIGH(KL0DE0<<1)
     RJMP FIND	
COL2:LDI R30,LOW(KL0DE1<<1)
     LDI R31,HIGH(KL0DE1<<1)
     RJMP FIND		
COL3:LDI R30,LOW(KL0DE2<<1)
     LDI R31,HIGH(KL0DE2<<1)
     RJMP FIND
COL4:LDI R30,LOW(KL0DE3<<1)
     LDI R31,HIGH(KL0DE3<<1)
     RJMP FIND	
FIND:
	LSR R21
	BRCC MATCH
	LPM R20,Z+
	RJMP FIND
MATCH:
	LPM R20,Z
	OUT PORTD,R20
	RET
.ORG 0X300
KL0DE0: .DB'0','1','2','3'
KL0DE1: .DB'4','5','6','7'
KL0DE2: .DB'8','9','A','B'
KL0DE3: .DB'C','D','E','F'


	