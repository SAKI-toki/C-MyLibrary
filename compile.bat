@echo off
setlocal enabledelayedexpansion
set STR=
for /r %%A in (*.cpp) do (
  set STR=!STR! %%A
)

g++ -std=c++17 -Wall -Wextra --pedantic-error -O3 -o bin\app.exe %STR% -I. 

endlocal