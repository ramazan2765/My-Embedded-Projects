/*
 * gpio.c
 *
 *  Created on: Dec 18, 2023
 *      Author: ramazan
 */
#include"gpio.h"

void gpio_perip_clock_en(GPIO_RegDef_t* pGpiox)
{
	 if(pGpiox == GPIOA)
		 GPIOA_CLOCK_ENABLE();
	 else if(pGpiox == GPIOB)
		 GPIOB_CLOCK_ENABLE();
	 else if(pGpiox == GPIOC)
		 GPIOC_CLOCK_ENABLE();
	 else if(pGpiox == GPIOD)
		 GPIOD_CLOCK_ENABLE();
	 else if(pGpiox == GPIOE)
		 GPIOE_CLOCK_ENABLE();
	 else if(pGpiox == GPIOF)
		 GPIOF_CLOCK_ENABLE();
	 else if(pGpiox == GPIOG)
		 GPIOG_CLOCK_ENABLE();
	 else if(pGpiox == GPIOH)
		 GPIOH_CLOCK_ENABLE();
	 else if(pGpiox == GPIOI)
		 GPIOI_CLOCK_ENABLE();
}

uint8_t get_port_code(const GPIO_RegDef_t* pGpioX)
{
	  if(pGpioX == GPIOA)
		  	  return GPIOA_PORT_CODE;
	  else if(pGpioX == GPIOB)
		  	  return GPIOB_PORT_CODE;
	  else if(pGpioX == GPIOB)
	  		  return GPIOB_PORT_CODE;
	  else if(pGpioX == GPIOC)
	  		  return GPIOC_PORT_CODE;
	  else if(pGpioX == GPIOD)
	  		  return GPIOD_PORT_CODE;
	  else if(pGpioX == GPIOE)
	  		  return GPIOE_PORT_CODE;
	  else if(pGpioX == GPIOF)
	  		  return GPIOF_PORT_CODE;
	  else if(pGpioX == GPIOG)
	  		  return GPIOG_PORT_CODE;
	  else if(pGpioX == GPIOH)
	  		  return GPIOH_PORT_CODE;
}

void gpio_init(GPIO_Handle_t* pGpio_handle)
{
	uint32_t temp=0;

	//1.GPIO Clock ENABLE
	gpio_perip_clock_en(pGpio_handle->pGpioX);

	//2.GPIO pin modes configuration

	if(pGpio_handle->gPIO_PingConfig.pin_mode <= GPIO_MODE_ANALOG){
	temp=(pGpio_handle->gPIO_PingConfig.pin_mode<<(2*pGpio_handle->gPIO_PingConfig.pin_number)); // 01,<28
	pGpio_handle->pGpioX->MODER &= ~(0b11 <<(2*pGpio_handle->gPIO_PingConfig.pin_number)); //register clear ettik
	pGpio_handle->pGpioX->MODER |=temp;

	//3. speed
	temp=pGpio_handle->gPIO_PingConfig.pin_speed<<(2*pGpio_handle->gPIO_PingConfig.pin_number);
	pGpio_handle->pGpioX->OSPEEDR &= ~(0b11<<(2*pGpio_handle->gPIO_PingConfig.pin_number));
	pGpio_handle->pGpioX->OSPEEDR |= temp;

	//4. pull_up pull_down
	temp=pGpio_handle->gPIO_PingConfig.pin_pupd<<(2*pGpio_handle->gPIO_PingConfig.pin_number);
	pGpio_handle->pGpioX->PUPDR &= ~(0b11 <<(2*pGpio_handle->gPIO_PingConfig.pin_number));
	pGpio_handle->pGpioX->PUPDR |= temp;
	 //5.otype
	temp=pGpio_handle->gPIO_PingConfig.pin_otyper<<(pGpio_handle->gPIO_PingConfig.pin_number);
	pGpio_handle->pGpioX->OTYPER &= ~(0b1<<pGpio_handle->gPIO_PingConfig.pin_number);
	pGpio_handle->pGpioX->OTYPER |= temp;
	  //6.alternate mode
	}
	else
	{
		//interrupt mode
		if(pGpio_handle->gPIO_PingConfig.pin_mode == GPIO_MODE_FE_IT)
		{
			EXTI->FTSR |= (1u << pGpio_handle->gPIO_PingConfig.pin_number);
			EXTI->RTSR &= ~(1U << pGpio_handle->gPIO_PingConfig.pin_number);
		}
		else if(pGpio_handle->gPIO_PingConfig.pin_mode == GPIO_MODE_RE_IT)
		{
			EXTI->RTSR |= (1U << pGpio_handle->gPIO_PingConfig.pin_number);
			EXTI->FTSR &= ~(1U << pGpio_handle->gPIO_PingConfig.pin_number);
		}
		else if(pGpio_handle->gPIO_PingConfig.pin_mode == GPIO_MODE_FRE_IT)
		{
			EXTI->FTSR |= (1u << pGpio_handle->gPIO_PingConfig.pin_number);
			EXTI->RTSR |= (1U << pGpio_handle->gPIO_PingConfig.pin_number);
		}
		//PORT Pin selection by SYSCFG_EXTICRx
		SYSCFG_CLOCK_ENABLE();

		uint32_t syscfg_exti_reg_no=pGpio_handle->gPIO_PingConfig.pin_number/4;
		uint32_t syscfg_exti_reg_bit_no = pGpio_handle->gPIO_PingConfig.pin_number%4;
		uint32_t port_code=get_port_code(pGpio_handle->pGpioX);

		// PORT D PIN 14
		SYSCFG->EXTICR[syscfg_exti_reg_no] |= (port_code << (syscfg_exti_reg_bit_no*4));
		EXTI-> IMR |= (1U << pGpio_handle->gPIO_PingConfig.pin_number);
		//ENABLE IMR
		//NVIC ENABLE

	}

}

void gpio_writeto_output_pin(GPIO_RegDef_t* pGpiox, uint8_t pin_no, uint8_t val)
{
	if(val==GPIO_PIN_SET)
		pGpiox->ODR |= (1u<<pin_no);
	else
		pGpiox->ODR &= ~(1u << pin_no);
}

void gpio_toggleto_output_pin(GPIO_RegDef_t* pGpiox,uint8_t pin_no)
{
	pGpiox->ODR ^= (1u<<pin_no);
}

void gpio_writeto_output_port(GPIO_RegDef_t*pGpiox,uint16_t val)
{
	pGpiox->ODR=val;
}

uint32_t gpio_read_input_pin(GPIO_RegDef_t* pGpiox, uint8_t pin_no)
{
	uint16_t res=0;

	res=(pGpiox->IDR & (1u<<pin_no));
	return res != 0 ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void enable_gpio_interrupt(uint32_t irq_num)
{
	 if(irq_num<32)
		 NVIC_ISERx->NVIC_ISER0 |= (1U<<irq_num);
	 else if(irq_num<64)
	 	 NVIC_ISERx->NVIC_ISER1 |= (1U<<irq_num%32);
	 else if(irq_num<=81)
	 	NVIC_ISERx->NVIC_ISER2 |= (1U<<irq_num%32);

}

void desable_gpio_interrupt(uint32_t irq_num)
{
	 if(irq_num<32)
		 NVIC_ICERx->NVIC_ICER0 |= (1U<<irq_num);
	 else if(irq_num<64)
	 	 NVIC_ICERx->NVIC_ICER1 |= (1U<<irq_num%32);
	 else if(irq_num<=81)
	 	NVIC_ICERx->NVIC_ICER2 |= (1U<<irq_num%32);

}

void clear_pending_reg(uint8_t pin_no)
{
	//CLEAR PR
	if(EXTI->PR & (1<<pin_no))
	   EXTI->PR |= (1U<<pin_no);
}


