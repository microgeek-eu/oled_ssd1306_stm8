/**
  ****************************************************************************
  * @file           : hw_setup.h
  * @brief          : Header for hw_setup.c file.
  *                   This file contains the hardware setup.
  *****************************************************************************
  * @attention
  *
  *  This code inspired on:
  *   OLED SSD1306 library for STM32
  *   https://github.com/lamik/OLED_SSD1306_STM32_HAL
  *
  *****************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __HW_SETUP_H
#define __HW_SETUP_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Exported symbols ----------------------------------------------------------*/
/**
  *  @brief  Hardware settings
  */

/**
  *  @brief  Define this symbol if @ref SystemClock_Config
  *          can disable all other peripherial clocks.
  */
#define DISABLE_OTHER_PERIPHERIAL_CLOCKS

/**
  *  @brief  Debug LED connection
  *  @note   LED is active when display GRAM is
  *          refreshed..
  */
#define TEST_Pin                GPIO_PIN_4
#define TEST_Port               GPIOD

/**
  *  @brief  Display module connections
  *  @note   If one of interface is not used the pin
  *          initialization is not executed.
  */
/* SPI Connection */
#define SSD1306_SCK_Pin         GPIO_PIN_5
#define SSD1306_SCK_Port        GPIOC
#define SSD1306_MOSI_Pin        GPIO_PIN_6
#define SSD1306_MOSI_Port       GPIOC
#define SSD1306_MISO_Pin        GPIO_PIN_7
#define SSD1306_MISO_Port       GPIOC

#define SSD1306_CS_Pin          GPIO_PIN_3
#define SSD1306_CS_Port         GPIOA

#define SSD1306_DC_Pin          GPIO_PIN_3
#define SSD1306_DC_Port         GPIOC
#define SSD1306_RESET_Pin       GPIO_PIN_4
#define SSD1306_RESET_Port      GPIOC

/* I2C Connection */
#define SSD1306_SCL_Pin         GPIO_PIN_4
#define SSD1306_SCL_Port        GPIOB
#define SSD1306_SDA_Pin         GPIO_PIN_5
#define SSD1306_SDA_Port        GPIOB

/**
  *  @brief  Interface and special settings
  *  @note   Please set only one interface.
  *          It won't work with both one time.
  */

/* #define SSD1306_SPI_CONTROL */
#define SSD1306_I2C_CONTROL

#ifdef SSD1306_I2C_CONTROL
  #ifdef SSD1306_SPI_CONTROL
    #error "Only one interface can be selected at a time!"
  #endif

  #define SSD1306_I2C_SPEED    200000
  #define SSD1306_I2C_ADDRESS  0x78
#endif

#ifdef SSD1306_SPI_CONTROL
  #ifdef SSD1306_I2C_CONTROL
    #error "Only one interface can be selected at a time!"
  #endif

  /* #define SPI_CS_HARDWARE_CONTROL */
#endif

/**
  *  @note When you use typical SPI SSD1306 module with I2C ennabled
  *        interface, there is no hardware reset circurity. So you may
  *        need to control RES pin too.
  *        If you add hardware reset circuit you can remark this line.
  */
/* #define SSD1306_RESET_USE */

/* Exported functions prototypes ---------------------------------------------*/
void MCU_Config(void);
void I2C_CWrite(uint8_t Address, uint8_t ControlByte, uint8_t *pData,
                uint16_t DataSize);
void SPI_Transmit(uint8_t *pData, uint16_t DataSize);

#endif /* __HW_SETUP_H */

/* *END OF FILE* */