SETLOCAL ENABLEDELAYEDEXPANSION
set COMPILER=C:\c64\cc65\bin\cc65
set ASSEMBLER=C:\c64\cc65\bin\ca65
set LINKER=C:\c64\cc65\bin\ld65
set INCLUDE=C:\c64\cc65\include
set LIB=C:\c64\cc65\lib\c64.lib
set X64="C:\Program Files\WinVICE\x64"
set PROGRUN="C:\c64\projects\FizzBuzz\fizzbuzz.prg"
REM: Delete old files
del %PROGRUN%
del *.o
del *.s
REM: Generate assembly for all files
for /f %%a IN ('dir /b *.c') do %COMPILER% -O -I %INCLUDE% -t c64 %%a -o %%~na.s
REM: Generate binary objects from assembly
for /f %%a IN ('dir /b *.s') do %ASSEMBLER% %%~na.s
REM: Merge binary objects into a single program binary
for /f %%a IN ('dir /b *.o') do %LINKER% -t c64 -o %PROGRUN% %%a %LIB%
%X64% %PROGRUN%
pause
