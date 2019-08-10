/**
  ****************************************************************************
  * @file           : interrupt.h
  * @brief          : Header for interrupt.c file.
  *                   This file contains the common interrupt handlers.
  ****************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __INTERRUPT_H
#define __INTERRUPT_H

/* Exported interrupt handlers -----------------------------------------------*/
void TIM2_Overflow_Handler(void) __interrupt(13);

#endif /* __INTERRUPT_H */

/* *END OF FILE* */
