/*
 * corem4.h
 *
 *  Created on: Jan 6, 2024
 *      Author: w11p128ssd
 */

#ifndef COREM4_H_
#define COREM4_H_

#include<stdint.h>
#include "stm32f407xx.h"

#define NVIC_ISER_BASEADDR (0xE000E100) //enable set interrupt register
#define NVIC_ICER_BASEADDR (0xE000E180) //enable clear interrupt register

typedef struct{
	volatile uint32_t NVIC_ISER0;
	volatile uint32_t NVIC_ISER1;
	volatile uint32_t NVIC_ISER2;
	volatile uint32_t NVIC_ISER3;
	volatile uint32_t NVIC_ISER4;
	volatile uint32_t NVIC_ISER5;
	volatile uint32_t NVIC_ISER6;
	volatile uint32_t NVIC_ISER7;
}NVIC_ISER_Reg_Def_t;

typedef struct{
	volatile uint32_t NVIC_ICER0;
	volatile uint32_t NVIC_ICER1;
	volatile uint32_t NVIC_ICER2;
	volatile uint32_t NVIC_ICER3;
	volatile uint32_t NVIC_ICER4;
	volatile uint32_t NVIC_ICER5;
	volatile uint32_t NVIC_ICER6;
	volatile uint32_t NVIC_ICER7;
}NVIC_ICER_Reg_Def_t;

#define NVIC_ISERx	((NVIC_ISER_Reg_Def_t*)NVIC_ISER_BASEADDR)
#define NVIC_ICERx	((NVIC_ICER_Reg_Def_t*)NVIC_ICER_BASEADDR)

void nvic_irqno_enable(uint32_t irq_num);
void nvic_irqno_desable(uint32_t irq_num);

#endif /* COREM4_H_ */
