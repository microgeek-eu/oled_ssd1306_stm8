@echo off
set CC_FLAGS=-mstm8 -lstm8 --std-c11 --opt-code-size --vc -DSTM8S207

echo Compiling library sources...
sdcc -c %CC_FLAGS% stm8s_adc2.c
sdcc -c %CC_FLAGS% stm8s_awu.c
sdcc -c %CC_FLAGS% stm8s_beep.c
sdcc -c %CC_FLAGS% stm8s_clk.c
sdcc -c %CC_FLAGS% stm8s_exti.c
sdcc -c %CC_FLAGS% stm8s_flash.c
sdcc -c %CC_FLAGS% stm8s_gpio.c
sdcc -c %CC_FLAGS% stm8s_i2c.c
sdcc -c %CC_FLAGS% stm8s_itc.c
sdcc -c %CC_FLAGS% stm8s_iwdg.c
sdcc -c %CC_FLAGS% stm8s_rst.c
sdcc -c %CC_FLAGS% stm8s_spi.c
sdcc -c %CC_FLAGS% stm8s_tim1.c
sdcc -c %CC_FLAGS% stm8s_tim2.c
sdcc -c %CC_FLAGS% stm8s_tim3.c
sdcc -c %CC_FLAGS% stm8s_tim4.c
sdcc -c %CC_FLAGS% stm8s_uart1.c
sdcc -c %CC_FLAGS% stm8s_uart3.c
sdcc -c %CC_FLAGS% stm8s_wwdg.c

echo Create library for STM8S207...
del stm8s207.lib
sdar -rc stm8s207.lib stm8s_adc2.rel stm8s_awu.rel stm8s_beep.rel stm8s_clk.rel stm8s_exti.rel stm8s_flash.rel stm8s_gpio.rel stm8s_i2c.rel stm8s_itc.rel stm8s_iwdg.rel stm8s_rst.rel stm8s_spi.rel stm8s_tim1.rel stm8s_tim2.rel stm8s_tim3.rel stm8s_tim4.rel stm8s_uart1.rel stm8s_uart3.rel stm8s_wwdg.rel

echo Deleting compiler artifacts...
del *.asm 
del *.lst
del *.rel
del *.sym

echo Library done.