::@echo off 

@for /d /r %%c in (Debug,settings,Release,Output,DebugConfig,Listings,Objects) do @if exist %%c ( rd /s /q "%%c" & echo     namelesstech.bat��ɾ��Ŀ¼%%c) 

@for /r  %%c in (*.uvguix.*,*.uvoptx,*.tmp,*.bak ,*.dep,*.sfr,Backup* ) do del "%%c"
pause