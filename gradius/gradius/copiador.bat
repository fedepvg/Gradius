@echo off

set targetDir=%1
set solutionDir=%2

echo Copiando archivos...

mkdir "%targetDir%res"

xcopy "%solutionDir%res" "%targetDir%res"/E /y /s

echo Archivos copiados