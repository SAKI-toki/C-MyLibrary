@echo off
rem bat�t�@�C����Shift JIS����Ȃ��Ɠ��삵�Ȃ�
setlocal enabledelayedexpansion
set STR=
for /r %%A in (src\*.cpp) do (
  set STR=!STR! %%A
)

rem �f�B���N�g���̍쐬
IF NOT EXIST "bin" (
mkdir bin
)
rem exe�̐���
g++ -std=c++2a -Wall -Wextra --pedantic-error -O3 -o bin\app.exe %STR% -I. --exec-charset=cp932

rem �f�B���N�g���̍쐬
IF NOT EXIST "asm" (
mkdir asm
)
rem �A�Z���u���̐���
rem g++ -std=c++2a -Wall -Wextra --pedantic-error -O3 -o asm\asm.s -S %STR% -I. --exec-charset=cp932

endlocal