@echo off
chcp 65001 >nul
:: Relance admin si besoin
net session >nul 2>&1
if %errorlevel% neq 0 (
  echo Relance avec droits administrateur...
  powershell -Command "Start-Process -Verb runAs '%~f0'"
  exit /b
)

echo Lancement du programme de vérification et installation...
"%~dp0check_php_mysql.exe"

echo.
echo Press any key to exit...
pause >nul
