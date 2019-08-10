/**
  *****************************************************************************
  * @file           : interrupt.C
  * @brief          : Common interrupt handlers
  *****************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "interrupt.h"

/* External callbacks called by service routines -----------------------------*/
extern void TIM2_OVFCallback(void);

/* Interrupt handlers --------------------------------------------------------*/
/**
  * @brief  TIM2 OVF Interrupt Handler for system tick
  * @param  None
  * @retval None
  */
void TIM2_Overflow_Handler(void) __interrupt(13)
{
  TIM2_ClearITPendingBit(TIM2_IT_UPDATE);

  TIM2_OVFCallback();
}

/* *END OF FILE* */
