@echo off

mkdir build
copy spl\*.* build\
copy oled\*.* build\
copy interrupt.* build\
copy hw_setup.* build\
copy main.* build\
cd build

echo.
echo Pass to the library build...
call make_lib.bat

echo.
echo Remove library build script...
del make_lib.bat

set CC_FLAGS=-mstm8 --std-c11 --opt-code-size --vc -DSTM8S103 -DUSE_STDPERIPH_DRIVER

echo.
echo Compiling SSD1306 sources...
sdcc -c %CC_FLAGS% oled_ssd1306.c
sdcc -c %CC_FLAGS% gfx_bw.c

echo.
echo Compiling main modules...
sdcc -c %CC_FLAGS% interrupt.c
sdcc -c %CC_FLAGS% hw_setup.c

echo.
echo Compiling main file...
sdcc %CC_FLAGS% --out-fmt-ihx stm8s103.lib interrupt.rel hw_setup.rel oled_ssd1306.rel gfx_bw.rel main.c

echo.
echo Create Intel HEX output...
packihx main.ihx >main.hex
del *.ihx

echo.
echo Remove compiler artifacts...
del *.asm
del *.lst
del *.rel
del *.rst
del *.sym
del *.cdb
del *.lk
del *.map

echo.
echo Deleting source files...
del *.c
del *.h
del *.lib

echo.
echo Populate HEX file...
cd ..
move build\main.hex main.hex
rmdir build

echo.
echo All done!
timeout /T 10