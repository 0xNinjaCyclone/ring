call ..\..\language\src\locatevc.bat
"C:\Qt\5.15.0\msvc2019\bin\qmake.exe" ring_qt512_light.pro -spec win32-msvc "CONFIG+=release"
"C:\Qt\Tools\QtCreator\bin\jom\jom.exe"
copy release\ringqt_light.dll ..\..\bin
