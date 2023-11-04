if exist "build\Debug\QtOpenGL.exe" (
    D:\opt\Qt\5.14.2\5.14.2\msvc2017_64\bin\windeployqt.exe build\Debug\QtOpenGL.exe
)

if exist "build\Release\QtOpenGL.exe" (
    D:\opt\Qt\5.14.2\5.14.2\msvc2017_64\bin\windeployqt.exe build\Release\QtOpenGL.exe
)
pause