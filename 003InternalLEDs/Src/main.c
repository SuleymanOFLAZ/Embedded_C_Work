/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(void);

int main(void)
{
	// Pointers
	uint32_t *p_clkPerGPIOD 	= (uint32_t *)0x40023830;
	uint32_t *p_pinModeGPIOD 	= (uint32_t *)0x40020C00;
	uint32_t *p_pinOutDataGPIOD = (uint32_t *)0x40020C14;

	//Masks
	uint32_t m_setClk 	= 0x00000008;

	uint32_t m_pinMode 	= 0x55000000;

	uint32_t m_setPin12 	= 0x00001000;
	uint32_t m_setPin13 	= 0x00002000;
	uint32_t m_setPin14 	= 0x00004000;
	uint32_t m_setPin15 	= 0x00008000;

	// Set Clock On
	*p_clkPerGPIOD 		= *p_clkPerGPIOD | m_setClk;
	*p_pinModeGPIOD 	= *p_pinModeGPIOD | m_pinMode;
	//*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD | m_setPin;

	/* Loop forever */
	while(1){
		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD | m_setPin12;
		delay();
		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD & ~(m_setPin12);
		delay();

		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD | m_setPin13;
		delay();
		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD & ~(m_setPin13);
		delay();

		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD | m_setPin14;
		delay();
		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD & ~(m_setPin14);
		delay();

		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD | m_setPin15;
		delay();
		*p_pinOutDataGPIOD 	= *p_pinOutDataGPIOD & ~(m_setPin15);
		delay();
	}
}

void delay(void){
	for(long i= 0; i<100000;i++);
}
