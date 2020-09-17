/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Horace Chow Chowh8 400177692////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include "tm4c1294ncpdt.h"
#include "Systick.h"
#include "PLL.h"


//output to motor
void PortE0E1_Init(void){
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;              // activate the clock for Port E
while((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R4) == 0){};        // allow time for clock to stabilize
  GPIO_PORTE_DEN_R = 0b00001111;                         // Enabled both as digital outputs
	GPIO_PORTE_DIR_R = 0b00001111;
return;
}
//Input from button
void PortM0M1_Init(void){
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R11;                 //activate the clock for Port M
while((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R11) == 0){};        //allow time for clock to stabilize
	GPIO_PORTM_DIR_R = 0b00000000;          // make PM0 an input, PM0 is reading if the button is pressed or not
  GPIO_PORTM_DEN_R = 0b00000001;
return;
}

//Turns on D2
void PortN0N1_Init(void){
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12;                 //activate the clock for Port N
while((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R12) == 0){};
	GPIO_PORTN_DIR_R=0b00000010;
	GPIO_PORTN_DEN_R=0b00000010;
return;
}

void PortB0B1_Init(void){
SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1;                 //activate the clock for Port N
while((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R1) == 0){};
	GPIO_PORTB_DIR_R=0b00000000;
	GPIO_PORTB_DEN_R=0b00001100;
return;
}

int pressed = 0;
int counter =0;
int temp_count=0;

int main(void){
	PLL_Init();
	SysTick_Init();
	PortB0B1_Init();
	PortM0M1_Init();
	PortN0N1_Init();
	PortE0E1_Init();

	while(1){
		if((~GPIO_PORTM_DATA_R&0b00000001)==1){
			GPIO_PORTN_DATA_R=0b00000010;
			for(counter=0;counter<512;counter++){
				GPIO_PORTE_DATA_R = 0b00001001;
				SysTick_Wait10ms(1);
				GPIO_PORTE_DATA_R = 0b00001100;
				SysTick_Wait10ms(1);
				GPIO_PORTE_DATA_R = 0b00000110;
				SysTick_Wait10ms(1);
				GPIO_PORTE_DATA_R = 0b00000011;
				SysTick_Wait10ms(1);
			}
		}
		GPIO_PORTN_DATA_R=0b00000000;
	}
}
