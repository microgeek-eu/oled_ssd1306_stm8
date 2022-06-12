/**
  *****************************************************************************
  * @file           : oled_ssd1306.h
  * @brief          : Header for SSD1306 display driver
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

#ifndef __OLED_SSD1306_H_
#define __OLED_SSD1306_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported defines ----------------------------------------------------------*/
/**
  * @brief  Resolution
  */
#define SSD1306_LCDWIDTH   128
#define SSD1306_LCDHEIGHT  64

/**
  * @brief  Select the instruction set
  * @note   Please set what functionality you want to use.
  *         Some functions need other functionalities.
  *         It should works automatically.
  *
  *         1 - will be compiled
  *         0 - won't be compiled
  */
#define GRAPHIC_ACCELERATION_COMMANDS  0
#define ADVANCED_GRAPHIC_COMMANDS      0

/**
  *****************************************************************************
  */

/**
  * @brief  Commands
  */
#define SSD1306_SETCONTRAST          0x81
#define SSD1306_DISPLAYALLON_RESUME  0xA4
#define SSD1306_DISPLAYALLON         0xA5
#define SSD1306_NORMALDISPLAY        0xA6
#define SSD1306_INVERTDISPLAY        0xA7
#define SSD1306_DISPLAYOFF           0xAE
#define SSD1306_DISPLAYON            0xAF
#define SSD1306_SETDISPLAYOFFSET     0xD3
#define SSD1306_SETCOMPINS           0xDA
#define SSD1306_SETVCOMDETECT        0xDB
#define SSD1306_SETDISPLAYCLOCKDIV   0xD5
#define SSD1306_SETPRECHARGE         0xD9
#define SSD1306_SETMULTIPLEX         0xA8
#define SSD1306_SETLOWCOLUMN         0x00
#define SSD1306_SETHIGHCOLUMN        0x10
#define SSD1306_SETSTARTLINE         0x40
#define SSD1306_MEMORYMODE           0x20
#define SSD1306_COLUMNADDR           0x21
#define SSD1306_PAGEADDR             0x22
#define SSD1306_COMSCANINC           0xC0
#define SSD1306_COMSCANDEC           0xC8
#define SSD1306_SEGREMAP             0xA0
#define SSD1306_CHARGEPUMP           0x8D
#define SSD1306_EXTERNALVCC          0x01
#define SSD1306_SWITCHCAPVCC         0x02

/**
  * @brief  Scrolling defines
  */
#define SSD1306_ACTIVATE_SCROLL                       0x2F
#define SSD1306_DEACTIVATE_SCROLL                     0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA              0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL               0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL                0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL  0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL   0x2A

/**
  * @brief  Advanced Graphic defines
  */
#define SSD1306_FADE_OUT  0x23
#define SSD1306_ZOOM_IN   0xD6

/**
  * @brief  Colors
  */
#define BLACK    0
#define WHITE    1
#define INVERSE  2

/* Private typedef -----------------------------------------------------------*/
/**
  * @brief  Scrolling enums
  */
typedef enum {
  SCROLL_EVERY_5_FRAMES,
  SCROLL_EVERY_64_FRAMES,
  SCROLL_EVERY_128_FRAMES,
  SCROLL_EVERY_256_FRAMES,
  SCROLL_EVERY_3_FRAMES,
  SCROLL_EVERY_4_FRAMES,
  SCROLL_EVERY_25_FRAMES,
  SCROLL_EVERY_2_FRAMES
} scroll_horizontal_speed;

/* Exported functions ------------------------------------------------------- */
/**
  * @brief  Functions
  */
#ifdef SSD1306_I2C_CONTROL
void SSD1306_I2cInit(void);
#endif

#ifdef SSD1306_SPI_CONTROL
void SSD1306_SpiInit(void);
#endif

/**
  * @brief  Configuration
  */
void SSD1306_DisplayON(uint8_t DisplayState);
void SSD1306_InvertColors(uint8_t Invert);
void SSD1306_RotateDisplay(uint8_t Rotate);
void SSD1306_SetContrast(uint8_t Contrast);

/**
  * @brief  Drawing
  */
void SSD1306_DrawPixel(int16_t x, int16_t y, uint8_t Color);
void SSD1306_Clear(uint8_t Color);
void SSD1306_Display(void);
void SSD1306_Bitmap(uint8_t *bitmap);

#if GRAPHIC_ACCELERATION_COMMANDS == 1
/**
  * @brief  Graphic Acceleration Commands
  */
void SSD1306_StartScrollRight(uint8_t StartPage, uint8_t EndPage,
       scroll_horizontal_speed Speed);
void SSD1306_StartScrollLeft(uint8_t StartPage, uint8_t EndPage,
       scroll_horizontal_speed Speed);
void SSD1306_StartScrollRightUp(uint8_t StartPage, uint8_t EndPage,
       scroll_horizontal_speed HorizontalSpeed, uint8_t VerticalOffset);
void SSD1306_StartScrollLeftUp(uint8_t StartPage, uint8_t EndPage,
       scroll_horizontal_speed HorizontalSpeed, uint8_t VerticalOffset);
void SSD1306_StopScroll(void);
#endif

#if ADVANCED_GRAPHIC_COMMANDS == 1
/**
  * @brief  Advanced Graphic Commands
  */
void SSD1306_StartFadeOut(uint8_t Interval);
void SSD1306_StartBlinking(uint8_t Interval);
void SSD1306_StopFadeOutOrBlinking(void);
void SSD1306_ZoomIn(uint8_t Zoom);
#endif

#endif /* __OLED_SSD1306_H_ */
