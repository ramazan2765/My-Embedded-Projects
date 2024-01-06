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

int main(void)
{
	GPIO_Handle_t GPIO_PIN_RED;
	GPIO_PIN_RED.pGpioX=GPIOD;
	GPIO_PIN_RED.gPIO_PingConfig.pin_number=GPIO_PIN_NO_14;
	GPIO_PIN_RED.gPIO_PingConfig.pin_mode=GPIO_MODE_OUT;
	GPIO_PIN_RED.gPIO_PingConfig.pin_otyper=GPIO_OTYPE_PP;
	GPIO_PIN_RED.gPIO_PingConfig.pin_pupd=GPIO_NO_PUPD;
	GPIO_PIN_RED.gPIO_PingConfig.pin_speed=GPIO_SPEED_MEDIUM;

	gpio_init(&GPIO_PIN_RED);

	GPIO_Handle_t GPIO_PIN_BLUE={GPIOD,{GPIO_PIN_NO_15,
										GPIO_MODE_OUT,
										GPIO_OTYPE_PP,
										GPIO_NO_PUPD,
										GPIO_SPEED_MEDIUM}
										};
	gpio_init(&GPIO_PIN_BLUE);

	GPIO_Handle_t PUSH_BUTTON={GPIOA,{GPIO_PIN_NO_0,
									  GPIO_MODE_IN,}
									  };
		gpio_init(&PUSH_BUTTON);

	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_14, GPIO_PIN_SET);
	gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_15, GPIO_PIN_SET);

	while(1){
		if(gpio_read_input_pin(GPIOA, GPIO_PIN_NO_0)==1){
		gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_14, GPIO_PIN_SET);
		}
		else{
		gpio_writeto_output_pin(GPIOD, GPIO_PIN_NO_14, GPIO_PIN_RESET);
		}

	}
}



