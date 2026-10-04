@echo off
setlocal
echo ========================================================
echo   Live Code Updater - Push Rooms 1-100 to GitHub
echo ========================================================
echo.
set /p REPO_URL="Enter your GitHub Repository URL (e.g. https://github.com/argharoy76/live-code-updater-rooms.git): "

if "%REPO_URL%"=="" (
    echo [ERROR] No URL entered. Exiting.
    pause
    exit /b 1
)

echo.
echo Setting remote origin to %REPO_URL% ...
git remote remove origin 2>nul
git remote add origin %REPO_URL%
git branch -M main

echo.
echo Pushing rooms 1 to 100 to GitHub...
git push -u origin main

if %ERRORLEVEL% EQU 0 (
    echo.
    echo ========================================================
    echo   SUCCESS! All 100 rooms pushed to GitHub!
    echo ========================================================
) else (
    echo.
    echo [ERROR] Git push failed. Please check your URL and permissions.
)
echo.
pause
