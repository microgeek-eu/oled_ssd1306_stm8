* -------------------------------------------------------------------
* OLED SSD1306 library for STM8
* Zbigniew Gibek <zbeegin@op.pl>
*
* ---
* This code is a port to STM8 of:
*
*   OLED SSD1306 library for STM32
*   https://github.com/lamik/OLED_SSD1306_STM32_HAL
*   Mateusz Salamon <mateusz@msalamon.pl>
*   Visit https://www.msalamon.pl/ for more information.
*
* ---
* The code also use STM8 Standard Peripherial Library
* which is copyrighted by STMicroelectronics.
* -------------------------------------------------------------------


Description:
------------
  The driver uses hardware I2C or SPI for communication. Only one
  medium can be used at a time.

  Library need at least 15KB of free Flash ROM and 3K of free RAM for
  full functionality. You can enable/disable functions to reduce
  amount of Flash ROM utilization.

  STM8 Standard Periherial Library (SPL) patched for SDCC compiler is
  included. (Non patched release can be obtained from
  https://www.st.com/en/embedded-software/stm8-embedded-software.html)

  The autobuilding "scripts" and SPL are ready for SDDC v3.9.0
  compiler (http://sdcc.sourceforge.net/).


Changes introduced while porting to the STM8 (Valid from 2019-05-23):
---------------------------------------------------------------------
- Default clock of MCU is 16MHz from HSI clock generator.
- TIM2 is used instead of SysTick. Timings are valid for 16MHz.
- TIM2 overflow interrupt call the TIM2_OVFCallback() to put delay
  and benchmark extra code in main module.
- The DMA settings and code has been removed due to STM8 and SPL
  constraints. DMA isn't standard peripherial in most of STM8 MCU's.
- The SPI SCK frequency is fixed at 8MHz. I2C SCL is set to 200kHz.
- Pins, ports and interface settings moved to top level hardware
  settings module.
- Add DISABLE_OTHER_PERIPHERIAL_CLOCKS symbol to disable/enable other
  than SPI/I2C/TIM2 peripherial clocks.
- Populate SSD1306_RESET_USE as main option. When you use typical SPI
  SSD1306 module with I2C enabled interface (via jumpers), there is
  no hardware reset circuit. So you may need to control RES pin too.
- Add separate USING_STRETCH_FONTS symbol to disable/enable font
  stretching feature.
- Add more fonts to include.


Known Issues:
-------------
- The display work only in SPI mode when SCK frequency not exceded
  8MHz. You can down the frequency to 4MHz. Lower clock below 4MHz
  doesn't seem to work. Not yet investigated why...


Final words:
------------
  Library tested on STM8S103F3/STM8S207R8 and SSD1306 based display.
  Both interfaces works as well. Advanced graphics has been tested
  with STM8S207R8, because STM8S103F3 has low amount of Flash ROM
  and SRAM.
  In case of STM8S103F3 you can decrease frame buffer to 128x32 and
  switch off most of graphics functions to run demo in a minimal
  functionality.
