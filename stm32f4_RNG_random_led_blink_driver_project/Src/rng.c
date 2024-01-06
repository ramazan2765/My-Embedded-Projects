/*
 * rng.c
 *
 *  Created on: Jan 6, 2024
 *      Author: ramazanyucel
 */
#include "rng.h"

void rng_init()
{
	//PLLON
	RCC->CR = PLLON;
	//
	while(!(RCC->CR  &  PLLREADY));

	// 1. RNG Clock Enable
	RNG_CLOCK_ENABLE();
	// 2. Enable Interrupt  RNG_CR
	RNG->CR |= IE;

	RNG->CR |= RNGEN;

	//INTERRUPT_ENABLE
	nvic_irqno_enable(IRQ_HASH_RNG);

}

uint32_t get_random_number()
{
		return RNG->DR;
}
