@echo off

cmake --build build

if errorlevel 1 (
    pause
    exit /b
)

"C:\Qt\6.11.1\mingw_64\bin\windeployqt.exe" build\aTerm.exe >nul

start "" build\aTerm.exe