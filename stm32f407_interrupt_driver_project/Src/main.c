/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************


// We configurate GPIO pin with REGISTER bits configurations.
// In this example we blink our LED-->>PORTD pin  13
*/


#include <stdint.h>
#include"gpio.h"

void delay()
{
	for(int i=0; i<250000; i++)
		;
}

void EXTI0_IRQHandler(void)
{
	delay();
	clear_pending_reg(GPIO_PIN_NO_0);
	gpio_toggleto_output_pin(GPIOD, GPIO_PIN_NO_15);
}

int main(void)
{
	/*GPIO_Handle_t GPIO_PIN_RED;
	GPIO_PIN_RED.pGpioX=GPIOD;
	GPIO_PIN_RED.gPIO_PingConfig.pin_number=GPIO_PIN_NO_14;
	GPIO_PIN_RED.gPIO_PingConfig.pin_mode=GPIO_MODE_OUT;
	GPIO_PIN_RED.gPIO_PingConfig.pin_otyper=GPIO_OTYPE_PP;
	GPIO_PIN_RED.gPIO_PingConfig.pin_pupd=GPIO_NO_PUPD;
	GPIO_PIN_RED.gPIO_PingConfig.pin_speed=GPIO_SPEED_MEDIUM;

	gpio_init(&GPIO_PIN_RED);*/

	GPIO_Handle_t GPIO_PIN_BLUE={GPIOD,{GPIO_PIN_NO_15,
										GPIO_MODE_OUT,
										GPIO_OTYPE_PP,
										GPIO_NO_PUPD,
										GPIO_SPEED_MEDIUM}
										};
	gpio_init(&GPIO_PIN_BLUE);

	    GPIO_Handle_t PUSH_BUTTON;
	    PUSH_BUTTON.pGpioX=GPIOA;
	    PUSH_BUTTON.gPIO_PingConfig.pin_number=GPIO_PIN_NO_0;
	    PUSH_BUTTON.gPIO_PingConfig.pin_mode=GPIO_MODE_FE_IT;
	    PUSH_BUTTON.gPIO_PingConfig.pin_pupd=GPIO_NO_PUPD;

		gpio_init(&PUSH_BUTTON);

	enable_gpio_interrupt(IRQ_EXTI0);
	while(1){
		int x=10;
		int y=20;
		int z=30;
	}
}



