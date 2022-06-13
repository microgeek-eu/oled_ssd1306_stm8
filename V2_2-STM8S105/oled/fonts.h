/**
  *****************************************************************************
  * @file           : fonts.h
  * @brief          : Include file with embeeded fonts
  *
  *****************************************************************************
  * @attention
  *
  *  This code is a part of:
  *   OLED SSD1306 library for STM32
  *   https://github.com/lamik/OLED_SSD1306_STM32_HAL
  *
  *  The MIT License.
  *  Created on: 25.05.2017
  *      Author: Mateusz Salamon
  *      www.msalamon.pl
  *      mateusz@msalamon.pl
  *
  *  Additional fonts authored by:
  *  Zbigniew Gibek, zbeegin@op.pl
  *
  *****************************************************************************
  */

#ifndef FONTS_FONTS_H_
#define FONTS_FONTS_H_

/* Private symbols -----------------------------------------------------------*/
/*
 * @brief  Set fonts you want to use
 */
#define FONT_6x4 0
#define FONT_7x5 1
#define FONT_7x7 0


/* Private includes ----------------------------------------------------------*/
/*
 *  Automatic includes
 */
#if (FONT_6x4 == 1)
  #include "font_6x4.h"
#endif

#if (FONT_7x5 == 1)
  #include "font_7x5.h"
#endif

#if (FONT_7x7 == 1)
  #include "font_7x7.h"
#endif

#endif /* FONTS_FONTS_H_ */
