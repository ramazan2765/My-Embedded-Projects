/*
 * gpio.h
 *
 *  Created on: Dec 18, 2023
 *      Author: ramaz
 */

#ifndef GPIO_H_
#define GPIO_H_

#include<stdint.h>
#include "stm32f407xx.h"


typedef struct{
	 uint8_t pin_number;
	 uint8_t pin_mode;
	 uint8_t pin_speed;
	 uint8_t pin_otyper;
	 uint8_t pin_pupd;
	 uint8_t pin_alternate_function_mode;
}GPIO_PingConfig_t;

typedef struct{
	GPIO_RegDef_t* pGpioX;
	GPIO_PingConfig_t  gPIO_PingConfig;
}GPIO_Handle_t;

//PRIVATE gpio_perip_clock_en(GPIO_RegDef_t* pGpiox);
void gpio_init(GPIO_Handle_t* pGpio_handle);
void gpio_writeto_output_pin(GPIO_RegDef_t* pGpiox, uint8_t pin_no, uint8_t val);
void gpio_writeto_output_port(GPIO_RegDef_t* pGpiox,uint16_t pin_no);
void gpio_toggleto_output_pin(GPIO_RegDef_t* pGpiox,uint8_t pin_no);
uint32_t gpio_read_input_pin(GPIO_RegDef_t* pGpiox, uint8_t pin_no);
void gpio_perip_clock_en(GPIO_RegDef_t* pGpiox);
uint8_t get_port_code(const GPIO_RegDef_t* pGpioX);

//GPIO MODES
enum{
	GPIO_MODE_IN,
	GPIO_MODE_OUT,
	GPIO_MODE_ALTERNATE,
	GPIO_MODE_ANALOG,
	GPIO_MODE_FE_IT,
	GPIO_MODE_RE_IT,
	GPIO_MODE_FR_IT,
};

//GPIO PIN NUMBER
enum{
	 GPIO_PIN_NO_0,
	 GPIO_PIN_NO_1,
	 GPIO_PIN_NO_2,
	 GPIO_PIN_NO_3,
	 GPIO_PIN_NO_4,
	 GPIO_PIN_NO_5,
	 GPIO_PIN_NO_6,
	 GPIO_PIN_NO_7,
	 GPIO_PIN_NO_8,
	 GPIO_PIN_NO_9,
	 GPIO_PIN_NO_10,
	 GPIO_PIN_NO_11,
	 GPIO_PIN_NO_12,
	 GPIO_PIN_NO_13,
	 GPIO_PIN_NO_14,
	 GPIO_PIN_NO_15,
};

//GPIO SPEED
enum{
	GPIO_SPEED_LOW,
	GPIO_SPEED_MEDIUM,
	GPIO_SPEED_HIGH,
	GPIO_SPEED_VERY_HIGH
};

//GPIO OUTPUT TYPE
enum{
	GPIO_OTYPE_PP,
	GPIO_OTYPE_OD
};

//GPIO PULL_UP PULLDOWN STATE
 enum{
	 GPIO_NO_PUPD,
	 GPIO_PIN_PU,
	 GPIO_PIN_PD
 };

 enum{
	 GPIO_PIN_RESET,
	 GPIO_PIN_SET
 };

 enum{
	 GPIO_PIN_GREEN=12,
	 GPIO_PIN_ORANGE,
	 GPIO_PIN_RED,
	 GPIO_PIN_BLUE
 };

 enum{
	 GPIOA_PORT_CODE,
	 GPIOB_PORT_CODE,
	 GPIOC_PORT_CODE,
	 GPIOD_PORT_CODE,
	 GPIOE_PORT_CODE,
	 GPIOF_PORT_CODE,
	 GPIOG_PORT_CODE,
	 GPIOH_PORT_CODE,
	 GPIOI_PORT_CODE,
 };

#define BUTTON_RELEASE 0
#define BUTTON_PRESS   1






#endif /* GPIO_H_ */
