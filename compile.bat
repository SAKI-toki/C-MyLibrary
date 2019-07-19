@echo off
rem batファイルはShift JISじゃないと動作しない
setlocal enabledelayedexpansion
set STR=
for /r %%A in (src\*.cpp) do (
  set STR=!STR! %%A
)

rem ディレクトリの作成
IF NOT EXIST "bin" (
mkdir bin
)
rem exeの生成
g++ -std=c++2a -Wall -Wextra --pedantic-error -O3 -o bin\app.exe %STR% -I. --exec-charset=cp932

rem ディレクトリの作成
IF NOT EXIST "asm" (
mkdir asm
)
rem アセンブリの生成
rem g++ -std=c++2a -Wall -Wextra --pedantic-error -O3 -o asm\asm.s -S %STR% -I. --exec-charset=cp932

endlocal