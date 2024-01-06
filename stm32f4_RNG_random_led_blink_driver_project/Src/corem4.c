/*
 * corem4.c
 *
 *  Created on: Jan 6, 2024
 *      Author: w11p128ssd
 */

#include"corem4.h"


void nvic_irqno_enable(uint32_t irq_num)
{
	 if(irq_num<32)
		 NVIC_ISERx->NVIC_ISER0 |= (1U<<irq_num);
	 else if(irq_num<64)
	 	 NVIC_ISERx->NVIC_ISER1 |= (1U<<irq_num%32);
	 else if(irq_num<=81)
	 	NVIC_ISERx->NVIC_ISER2 |= (1U<<irq_num%32);

}

void nvic_irqno_desable(uint32_t irq_num)
{
	 if(irq_num<32)
		 NVIC_ICERx->NVIC_ICER0 |= (1U<<irq_num);
	 else if(irq_num<64)
	 	 NVIC_ICERx->NVIC_ICER1 |= (1U<<irq_num%32);
	 else if(irq_num<=81)
	 	NVIC_ICERx->NVIC_ICER2 |= (1U<<irq_num%32);

}
