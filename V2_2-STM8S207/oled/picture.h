/**
  *****************************************************************************
  * @file           : picture.h
  * @brief          : Include file with embedded graphics
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

#ifndef __PICTURE_H_
#define __PICTURE_H_

/* Constants -----------------------------------------------------------------*/
const uint8_t picture[] = {
  0xff,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xc1,0xc1,0xc1,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
  0xc1,0xc1,0xc1,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0xff,
  0xff,0x00,0x00,0x00,0x00,0x00,0xfc,0xfc,0xfc,0x18,0x0c,0x0c,0xfc,0xfc,0xf8,0x18,
  0x0c,0x0c,0xfc,0xfc,0xf8,0x00,0x00,0x78,0x7c,0xec,0xcc,0xcc,0x98,0x80,0x00,0x98,
  0xcc,0xcc,0xcc,0xcc,0xfc,0xfc,0xf8,0x00,0x00,0xff,0xff,0xff,0x00,0x00,0x98,0xcc,
  0xcc,0xcc,0xcc,0xfc,0xfc,0xf8,0x00,0x00,0xfc,0xfc,0xfc,0x18,0x0c,0x0c,0xfc,0xfc,
  0xf8,0x18,0x0c,0x0c,0xfc,0xfc,0xf8,0x00,0x00,0xe0,0xf8,0xf8,0x1c,0x0c,0x0c,0x1c,
  0xfc,0xf8,0xf0,0x00,0xfc,0xfc,0xfc,0x18,0x0c,0x0c,0xfc,0xfc,0xf8,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xfc,0xfc,0xfc,0x18,0x0c,0x1c,0xfc,0xf8,0xf0,0x00,0x00,
  0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
  0xff,0x00,0x00,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x00,
  0x00,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x06,0x0c,0x0c,0x0c,0x0f,0x07,0x07,0x00,0x07,
  0x0f,0x0f,0x0c,0x0c,0x0f,0x0f,0x0f,0x00,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x07,0x0f,
  0x0f,0x0c,0x0c,0x0f,0x0f,0x0f,0x00,0x00,0x0f,0x0f,0x0f,0x00,0x80,0xc0,0xcf,0xcf,
  0xcf,0xc0,0xc0,0x80,0x8f,0x0f,0x0f,0x00,0x00,0x03,0x07,0x0f,0x0e,0x0c,0x0c,0x0e,
  0x07,0x07,0x01,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x00,0x0f,0x0f,0x0f,0x00,0x00,0x0e,
  0x0e,0x0e,0x00,0x00,0x00,0xff,0xff,0xff,0x06,0x0c,0x0e,0x0f,0x07,0x03,0x00,0x00,
  0x0f,0x0f,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
  0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xe0,0xfe,0xff,0xff,0x0f,0x01,
  0x03,0x03,0x87,0xff,0xff,0xfe,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
  0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,0xe0,0xe0,0xe0,
  0xe0,0xe0,0xe0,0xe0,0xe0,0xf0,0xfc,0x7e,0x3f,0x1f,0x07,0x03,0x01,0x00,0x00,0x00,
  0x20,0x3c,0x3f,0x3f,0x3f,0x3f,0x3c,0x3c,0x3c,0x3c,0x3c,0x7c,0xf8,0xf0,0xe0,0xc0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
  0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0xfc,0xff,0xff,0xff,0x07,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
  0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0xff,0xff,0xff,0x9f,0x9f,
  0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xff,0xff,0xff,0x1f,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
  0xff,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x81,0x87,0x87,0x87,0x87,0x87,
  0x87,0x87,0x87,0x87,0x87,0x8f,0x8f,0x8f,0x8f,0x9e,0x9e,0x9e,0xbc,0xbc,0xbc,0xbc,
  0xbc,0xb8,0xb8,0xb8,0xb8,0xbc,0xbc,0xbc,0xbe,0x9f,0x8f,0x87,0x80,0x80,0x80,0x80,
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
  0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0xff
};

#endif /* __PICTURE_H */