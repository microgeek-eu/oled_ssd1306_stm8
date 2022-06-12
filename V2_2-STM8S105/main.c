/**
  *****************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  *****************************************************************************
  * @attention
  *
  *  Benchmark code based on:
  *    OLED SSD1306 library for STM32
  *    https://github.com/lamik/OLED_SSD1306_STM32_HAL
  *    Mateusz Salamon <mateusz@msalamon.pl>
  *
  *****************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

#include "main.h"
#include "interrupt.h"
#include "hw_setup.h"

/* Private includes ----------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "oled_ssd1306.h"
#include "gfx_bw.h"
#include "fonts.h"
/* #include "picture.h" */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static volatile uint16_t timer_1s;
static volatile uint16_t delay_1ms;

/* Private function prototypes -----------------------------------------------*/
/* Variables -----------------------------------------------------------------*/

/* Main function -------------------------------------------------------------*/
/**
  * @brief  The application entry point
  * @retval int - don't care
  */
int main(void)
{
  /* STM8 configuration */
  MCU_Config();

  /* SSD1306 configuration */
#ifdef SSD1306_I2C_CONTROL
  SSD1306_I2cInit();
#endif
#ifdef SSD1306_SPI_CONTROL
  SSD1306_SpiInit();
#endif

  /* Benchmark variables */
  uint16_t frames       = 0;
  uint16_t fps          = 0;
  uint16_t loops        = 0;
  uint16_t loops_overal = 0;

  char     fps_c[15];

  /* SSD1306 demo code */

  /*   SSD1306_Bitmap((uint8_t*)picture);
   *   Delay_ms(5000);
   */
  GFX_SetFont(font_6x4);
  GFX_SetFontSize(1);

  /*  SSD1306_StartScrollLeftUp(0, 7, SCROLL_EVERY_4_FRAMES, 1);
   *  SSD1306_StartScrollLeft(0, 7, SCROLL_EVERY_4_FRAMES);
   *  SSD1306_StartBlinking(1);
   *  SSD1306_ZoomIn(1);
   */

  /* Infinite loop */
  for(;;) {

    if(!timer_1s) {
      timer_1s     = 1000;
      fps          = frames;
      frames       = 0;
      loops_overal = loops;
      loops        = 0;
    }

    sprintf(fps_c, "LOOP: %04d", loops_overal);
    SSD1306_Clear(WHITE);
    GFX_DrawString(0, 0, fps_c, WHITE, BLACK);
    sprintf(fps_c, " FPS: %02d", fps);
    GFX_DrawString(0, 8, fps_c, WHITE, BLACK);
    frames++;

    GPIO_WriteHigh(TEST_Port, TEST_Pin);
    SSD1306_Display();
    GPIO_WriteLow(TEST_Port, TEST_Pin);
    loops++;
  }
}


/* Public user code ----------------------------------------------------------*/
/**
  * @brief  TIM2 based delay, in miliseconds
  * @param   Time: Delay in ms, max delay is 32000
  * @retval None
  */
void Delay_ms(uint16_t Time)
{
  delay_1ms = Time;
  /* Wait for TIM2 for make his job */
  while(delay_1ms) {};
}

/**
  * @brief  TIM2 Callback
  * @param  None
  * @retval None
  */
void TIM2_OVFCallback(void)
{
  /* Internal ticks */
  --delay_1ms;
  /* Benchmark ticks */
  if(timer_1s) --timer_1s;
}

/* *END OF FILE* */
