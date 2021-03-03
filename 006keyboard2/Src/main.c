/* Simple 2x2 keyboard project */
#include <stdint.h>
#include <stdio.h>

void printOutput(uint8_t x);
void delay(void);

int main(void)
{
	//Register Pointers
	uint32_t volatile *const pRCC = (uint32_t *)0x40023820;
	uint32_t volatile *const GPIOa_m = (uint32_t *)0x40020000;
	uint32_t volatile *const GPIOa_o = (uint32_t *)0x40020014;
	uint32_t volatile *const GPIOb_m = (uint32_t *)0x40020400;
	uint32_t volatile *const GPIOb_r = (uint32_t *)0x4002040C;
	uint32_t volatile *const GPIOb_i = (uint32_t *)0x40020410;

	// Initializing required bits
	*pRCC |= 0x00000003;  // Peripheral clock en register
	*GPIOa_m |= 0x00000005; // Setting GPIOA mode
	*GPIOa_m &= 0xFFFFFFF5; // Setting GPIOA mode
	*GPIOb_m &= 0xFFFFFFF0; // Setting GPIOB mode
	*GPIOb_r &= 0x00000000; // Setting pull-up resistors
	*GPIOb_r |= 0x00000005; // Setting pull-up resistors

	// Setting Rows to 1
	*GPIOa_o |= 0x00000003; // We have only two rows :)


	/* Loop forever */
	while(1){
		*GPIOa_o |= 0x00000003;
		*GPIOa_o &= 0xFFFFFFFE;
		if( !(*GPIOb_i & ~(0xFFFFFFFE)) ){
			delay();
			printOutput(0);
		}
		else if( !(*GPIOb_i & ~(0xFFFFFFFD)) ){
			delay();
			printOutput(1);
		}

		*GPIOa_o |= 0x00000003;
		*GPIOa_o &= 0xFFFFFFFD;
		if( !(*GPIOb_i & ~(0xFFFFFFFE)) ){
			delay();
			printOutput(2);
		}
		else if( !(*GPIOb_i & ~(0xFFFFFFFD)) ){
			delay();
			printOutput(3);
		}
	}
}

void printOutput(uint8_t x){
	switch(x)
	{
	case 0:
		printf("Pressed BUTTON-1 \n");
		break;
	case 1:
		printf("Pressed BUTTON-2 \n");
		break;
	case 2:
		printf("Pressed BUTTON-3 \n");
		break;
	case 3:
		printf("Pressed BUTTON-4 \n");
		break;
	}
}

void delay(void){
	for(uint32_t volatile i=0; i < 300000; i++);
}
