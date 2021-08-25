@echo on

rem copy inlib library
set configure=%1
set IDE_Source=%2
set solutionName=%3
set current_path=%CD%
set Project_Path=%current_path%\%solutionName%\%configure%

rem 更新 QuiBaseUi
echo -----------------QuiBaseUi---------------
set QuiBaseUi_dll=QuiBaseUi
set QuiBaseUi_dll_Path=%IDE_Source%\%QuiBaseUi_dll%\bin
if %configure%==Debug (xcopy /a /y  %QuiBaseUi_dll_Path%\%QuiBaseUi_dll%d.dll %Project_Path%) else (xcopy /a /y  %QuiBaseUi_dll_Path%\%QuiBaseUi_dll%.dll %Project_Path%)
