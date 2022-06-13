/**
  *****************************************************************************
  * @file           : oled_ssd1306.c
  * @brief          : SSD1306 display driver
  *
  *****************************************************************************
  * @attention
  *
  *  This code is a part of:
  *   OLED SSD1306 library for STM32
  *   https://github.com/lamik/OLED_SSD1306_STM32_HAL
  *
  *  The MIT License.
  *  Created on: 27.01.2017
  *      Author: Mateusz Salamon
  *      www.msalamon.pl
  *      mateusz@msalamon.pl
  *
  *****************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm8s.h"
#include "hw_setup.h"

/* Private includes ----------------------------------------------------------*/
#include <stdint.h>
#include <string.h>

#include "oled_ssd1306.h"

/* Private variables ---------------------------------------------------------*/
static uint8_t buffer[SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8];

/* Exported functions ------------------------------------------------------- */
/**
  * @brief  Send command to the controller
  * @param  com: specifies the signgle command to send
  * @retval None
  */
void SSD1306_Command(uint8_t com)
{
#ifdef SSD1306_I2C_CONTROL
  /* ***I2C*** */
  I2C_CWrite(SSD1306_I2C_ADDRESS, 0x00, &com, sizeof(com));
#endif
#ifdef SSD1306_SPI_CONTROL
  /* ***SPI*** */
  GPIO_WriteLow(SSD1306_DC_Port, SSD1306_DC_Pin);
#ifndef SPI_CS_HARDWARE_CONTROL
  GPIO_WriteLow(SSD1306_CS_Port, SSD1306_CS_Pin);
#endif
  SPI_Transmit(&com, 1);
#ifndef SPI_CS_HARDWARE_CONTROL
  GPIO_WriteHigh(SSD1306_CS_Port, SSD1306_CS_Pin);
#endif
#endif
}

/**
  * @brief  Send data to the controller
  * @param  dat: specifies the single data to send
  * @retval None
  */
void SSD1306_Data(uint8_t dat)
{
#ifdef SSD1306_I2C_CONTROL
  /* ***I2C*** */
  I2C_CWrite(SSD1306_I2C_ADDRESS, 0x40, &dat, sizeof(dat));
#endif
#ifdef SSD1306_SPI_CONTROL
  /* ***SPI*** */
  GPIO_WriteHigh(SSD1306_DC_Port, SSD1306_DC_Pin);
#ifndef SPI_CS_HARDWARE_CONTROL
  GPIO_WriteLow(SSD1306_CS_Port, SSD1306_CS_Pin);
#endif
  SPI_Transmit(&dat, 1);
#ifndef SPI_CS_HARDWARE_CONTROL
  GPIO_WriteHigh(SSD1306_CS_Port, SSD1306_CS_Pin);
#endif
#endif
}

#if defined(SSD1306_SPI_CONTROL) || defined(SSD1306_RESET_USE)
/**
  * @brief  Pull reset pin to ground for 5ms to reset controller
  * @param  None
  * @retval None
  */
void SSD1306_Reset(void)
{
  GPIO_WriteLow(SSD1306_RESET_Port, SSD1306_RESET_Pin);
  Delay_ms(5);
  GPIO_WriteHigh(SSD1306_RESET_Port, SSD1306_RESET_Pin);
}
#endif

/**
  * @brief  Configuration functions
  */

/**
  * @brief  Set the global inversion mode
  * @param  Invert: Set to one for enable inverse mode
  * @retval None
  */
void SSD1306_InvertColors(uint8_t Invert)
{
  SSD1306_Command(Invert ? SSD1306_INVERTDISPLAY : SSD1306_NORMALDISPLAY);
}

/**
  * @brief  Set the display rotation
  * @param  Rotate: Set to one for enable rotated mode
  * @retval None
  */
void SSD1306_RotateDisplay(uint8_t Rotate)
{
  if(Rotate > 1) Rotate = 1;

  SSD1306_Command(SSD1306_SEGREMAP | (0x01 & Rotate));
               /* Set Segment Re-Map Default                        */
               /* 0xA0  (0x00) => column Address 0 mapped to 127    */
               /* 0xA1  (0x01) => Column Address 127 mapped to 0    */

  SSD1306_Command(SSD1306_COMSCANINC | (0x08 & (Rotate << 3)));
               /* Set COM Output Scan Direction                     */
               /* 0xC0  (0x00) => normal mode (RESET) Scan from     */
               /*  COM0 to COM[N-1];Where N is the Multiplex ratio. */
               /* 0xC8  (0xC8) => remapped mode. Scan from COM[N-1] */
               /*  to COM0;;Where N is the Multiplex ratio.         */
}

/**
  * @brief  Set the display on or off
  * @param  DisplayState: Set the current display state
  * @retval None
  */
void SSD1306_DisplayON(uint8_t DisplayState)
{
  SSD1306_Command(DisplayState ? SSD1306_DISPLAYON : SSD1306_DISPLAYOFF);
}

/**
  * @brief  Set the display contrast value
  * @param  Contrast: Contrast value
  * @retval None
  */
void SSD1306_SetContrast(uint8_t Contrast)
{
	/* Set Contrast Control */
  SSD1306_Command(SSD1306_SETCONTRAST);
  SSD1306_Command(Contrast);
}

#if GRAPHIC_ACCELERATION_COMMANDS == 1
/**
  * @brief  Graphic Acceleration Command
  */

/**
  * @brief  Enable the auto scroll functionality, right direction
  * @param  StartPage: Internal starting page number
  *         EndPage  : Internal endining page number
  *         Speed    : Frames per second from @ref scroll_horizontal_speed
  * @retval None
  */
void SSD1306_StartScrollRight(uint8_t StartPage, uint8_t EndPage, uint8_t Speed)
{
  SSD1306_Command(SSD1306_RIGHT_HORIZONTAL_SCROLL);
  SSD1306_Command(0x00);
  SSD1306_Command(StartPage);
  SSD1306_Command(Speed);
  SSD1306_Command(EndPage);
  SSD1306_Command(SSD1306_ACTIVATE_SCROLL);
}

/**
  * @brief  Enable the auto scroll functionality, left direction
  * @param  StartPage: Internal starting page number
  *         EndPage  : Internal endining page number
  *         Speed    : Frames per second from @ref scroll_horizontal_speed
  * @retval None
  */
void SSD1306_StartScrollLeft(uint8_t StartPage, uint8_t EndPage, uint8_t Speed)
{
  SSD1306_Command(SSD1306_LEFT_HORIZONTAL_SCROLL);
  SSD1306_Command(0x00);
  SSD1306_Command(StartPage);
  SSD1306_Command(Speed);
  SSD1306_Command(EndPage);
  SSD1306_Command(SSD1306_ACTIVATE_SCROLL);
}

/**
  * @brief  Enable the auto scroll functionality, two direction
  * @param  Direction       : Direction
  *         StartPage       : Internal starting page number
  *         EndPage         : Internal endining page number
  *         HorizontalSpeed : Frames per second from
  *                           @ref scroll_horizontal_speed
  *         VerticalOffset  :
  * @retval None
  */
void SSD1306_ScrollingHorVer(uint8_t Direction, uint8_t StartPage,
       uint8_t EndPage, uint8_t HorizontalSpeed, uint8_t VerticalOffset)
{
  if(VerticalOffset > 127) VerticalOffset = 127;
  SSD1306_Command(Direction);
  SSD1306_Command(0x00);
  SSD1306_Command(StartPage);
  SSD1306_Command(HorizontalSpeed);
  SSD1306_Command(EndPage);
  SSD1306_Command(VerticalOffset);
  SSD1306_Command(SSD1306_ACTIVATE_SCROLL);
}

/**
  * @brief  Enable the auto scroll finctionality, left and up direction
  * @param  Direction       : Direction
  *         StartPage       : Internal starting page number
  *         EndPage         : Internal endining page number
  *         HorizontalSpeed : Frames per second from
  *                           @ref scroll_horizontal_speed
  *         VerticalOffset  :
  * @retval None
  */
void SSD1306_StartScrollLeftUp(uint8_t StartPage, uint8_t EndPage,
       uint8_t HorizontalSpeed, uint8_t VerticalOffset)
{
  SSD1306_ScrollingHorVer(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL,
                          StartPage, EndPage, HorizontalSpeed, VerticalOffset);
}

/**
  * @brief  Enable the auto scroll finctionality, right and up direction
  * @param  Direction       : Direction
  *         StartPage       : Internal starting page number
  *         EndPage         : Internal endining page number
  *         HorizontalSpeed : Frames per second from
  *                           @ref scroll_horizontal_speed
  *         VerticalOffset  :
  * @retval None
  */
void SSD1306_StartScrollRightUp(uint8_t StartPage, uint8_t EndPage,
       uint8_t HorizontalSpeed, uint8_t VerticalOffset)
{
  SSD1306_ScrollingHorVer(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL,
                          StartPage, EndPage, HorizontalSpeed, VerticalOffset);
}

/**
  * @brief  Disable the auto scroll finctionality
  * @param  None
  * @retval None
  */
void SSD1306_StopScroll(void)
{
  SSD1306_Command(SSD1306_DEACTIVATE_SCROLL);
}
#endif

/**
  * @brief  Advanced Graphic Commands
  */
#if ADVANCED_GRAPHIC_COMMANDS == 1
/**
  * @brief  Enable auto fade out finctionality
  * @param  Interval : Time between fade steps
  * @retval None
  */
void SSD1306_StartFadeOut(uint8_t Interval)
{
  SSD1306_Command(SSD1306_FADE_OUT);
  SSD1306_Command(0x20 | (0x0F & Interval));
}

/**
  * @brief  Enable auto blink functionality
  * @param  Interval : Time between blink steps
  * @retval None
  */
void SSD1306_StartBlinking(uint8_t Interval)
{
  SSD1306_Command(SSD1306_FADE_OUT);
	SSD1306_Command(0x30 | (0x0F & Interval));
}

/**
  * @brief  Disable auto fade out/blinking functionality
  * @param  Interval : Time between fade steps
  * @retval None
  */
void SSD1306_StopFadeOutOrBlinking(void)
{
  SSD1306_Command(SSD1306_FADE_OUT);
  SSD1306_Command(0x00);
}

/**
  * @brief  Enable or disable zoom functionality
  * @param  Zoom : Set to 1 to enable zoom
  * @retval None
  */
void SSD1306_ZoomIn(uint8_t Zoom)
{
  SSD1306_Command(SSD1306_ZOOM_IN);
  SSD1306_Command(Zoom ? 0x01 : 0x00);
}
#endif

/**
  * @brief  Send the SSD1306 initialization set of commands
  * @param  None
  * @retval None
  */
void SSD1306_Init(void)
{
  /* Display Off */
  SSD1306_Command(SSD1306_DISPLAYOFF);
  SSD1306_Command(0x00);

  SSD1306_Command(SSD1306_SETHIGHCOLUMN);
  SSD1306_Command(0x40);
  /* Set addressing mode */
  SSD1306_Command(SSD1306_MEMORYMODE);
  /* Horizontal Addressing Mode */
  SSD1306_Command(0x00);

  SSD1306_SetContrast(0xFF);
  SSD1306_RotateDisplay(1);

  /* Set Normal Display */
  SSD1306_Command(SSD1306_NORMALDISPLAY);
  /* Select Multiplex Ratio */
  SSD1306_Command(SSD1306_SETMULTIPLEX);
  /* Default => 0x3F (1/64 Duty)	0x1F(1/32 Duty) */
  SSD1306_Command(0x3F);
  /* Setting Display Offset */
  SSD1306_Command(SSD1306_SETDISPLAYOFFSET);
  SSD1306_Command(0x00);  /* 00H Reset */
  /* Set Display Clock */
  SSD1306_Command(SSD1306_SETDISPLAYCLOCKDIV);
  SSD1306_Command(0x80);  /* 105HZ */
  /* Set Pre-Charge period */
  SSD1306_Command(SSD1306_SETPRECHARGE);
  SSD1306_Command(0x22);

  /* Set COM Hardware Configuration */
  SSD1306_Command(SSD1306_SETCOMPINS);
  SSD1306_Command(0x22);
              /* Alternative COM Pin---See IC Spec page 34       */
              /* (0x02)=> A4=0;Sequential COM pin configuration; */
              /*          A5=0;Disable COM Left/Right remap      */
  /* Set Deselect Vcomh level */
  SSD1306_Command(SSD1306_SETVCOMDETECT);
  SSD1306_Command(0x40);
  /* Set Charge Pump */
  SSD1306_Command(SSD1306_CHARGEPUMP);
  /* SSD1306_Command(0x10); */  /* Disable Charge Pump */
  SSD1306_Command(0x14);  /* Endable Charge Pump */
  /* Entire Display ON */
  SSD1306_Command(SSD1306_DISPLAYALLON_RESUME);

#if GRAPHIC_ACCELERATION_COMMANDS == 1
  SSD1306_StopScroll();
#endif

#if ADVANCED_GRAPHIC_COMMANDS == 1
  SSD1306_StopFadeOutOrBlinking();
#endif

  SSD1306_DisplayON(1);
}

#ifdef SSD1306_I2C_CONTROL
/**
  * @brief  Initialize SSD1306 through I2C, extra code container
  * @param  None
  * @retval None
  */
void SSD1306_I2cInit(void)
{
#if defined(SSD1306_RESET_USE)
  /* For reconfigured SPI module as I2C */
  SSD1306_Reset();
#endif
  SSD1306_Init();
}
#endif

#ifdef SSD1306_SPI_CONTROL
/**
  * @brief  Initialize SSD1306 through SPI, extra code container
  * @param  None
  * @retval None
  */
void SSD1306_SpiInit(void)
{
#if defined(SSD1306_RESET_USE)
  SSD1306_Reset();
#endif
  SSD1306_Init();
}
#endif

/**
  * @brief  Put single pixel in frame buffer
  * @param  x, y : Pixel position
  *         Color: Pixel color
  * @retval None
  */
void SSD1306_DrawPixel(int16_t x, int16_t y, uint8_t Color)
{
  if((x < 0) || (x >= SSD1306_LCDWIDTH) || (y < 0) || (y >= SSD1306_LCDHEIGHT))
    return;

  switch(Color)
  {
    case WHITE:
      buffer[x + (y / 8) * SSD1306_LCDWIDTH] |=  (1 << (y & 7));
      break;
    case BLACK:
      buffer[x + (y / 8) * SSD1306_LCDWIDTH] &= ~(1 << (y & 7));
      break;
    case INVERSE:
      buffer[x + (y / 8) * SSD1306_LCDWIDTH] ^=  (1 << (y & 7));
      break;
    default:
      break;
  }
}

/**
  * @brief  Clear the frame buffer
  * @param  Color : Fill color
  * @retval None
  */
void SSD1306_Clear(uint8_t Color)
{
  switch(Color)
  {
    case WHITE:
      memset(buffer, 0xFF, (SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8));
      break;
    case BLACK:
      memset(buffer, 0x00, (SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8));
      break;
    default:
      break;
  }
}

/**
  * @brief  Send buffer to GCRAM
  * @param  None
  * @retval None
  */
void SSD1306_Display(void)
{
  SSD1306_Command(SSD1306_PAGEADDR);
  SSD1306_Command(0x00);
  SSD1306_Command(0x07);

#ifdef SSD1306_I2C_CONTROL
  I2C_CWrite(SSD1306_I2C_ADDRESS, 0x40, (uint8_t*)&buffer,
            (SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8));
#endif

#ifdef SSD1306_SPI_CONTROL
  GPIO_WriteHigh(SSD1306_DC_Port, SSD1306_DC_Pin);
  #ifndef SPI_CS_HARDWARE_CONTROL
    GPIO_WriteLow(SSD1306_CS_Port, SSD1306_CS_Pin);
  #endif
  SPI_Transmit((uint8_t*)&buffer, (SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8));
  #ifndef SPI_CS_HARDWARE_CONTROL
    GPIO_WriteHigh(SSD1306_CS_Port, SSD1306_CS_Pin);
  #endif
#endif
}

/**
  * @brief  Display bitmap directly on screen
  * @param  bitmap : Pointer to the bitmap data
  * @retval None
  */
void SSD1306_Bitmap(uint8_t *bitmap)
{
  SSD1306_Command(SSD1306_PAGEADDR);
  SSD1306_Command(0x00);
  SSD1306_Command(0x07);

#ifdef SSD1306_I2C_CONTROL
  I2C_CWrite(SSD1306_I2C_ADDRESS, 0x40, bitmap,
            (SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8));
#endif

#ifdef SSD1306_SPI_CONTROL
  GPIO_WriteHigh(SSD1306_DC_Port, SSD1306_DC_Pin);
  #ifndef SPI_CS_HARDWARE_CONTROL
    GPIO_WriteLow(SSD1306_CS_Port, SSD1306_CS_Pin);
  #endif
  SPI_Transmit(bitmap, (SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8));
  #ifndef SPI_CS_HARDWARE_CONTROL
    GPIO_WriteHigh(SSD1306_CS_Port, SSD1306_CS_Pin);
  #endif
#endif
}
