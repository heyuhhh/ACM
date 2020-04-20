::注意使用ansi编码保存
@echo off  
:loop  
    D:\vim\ACM\对拍\maker.exe > D:\vim\ACM\对拍\data.txt
    D:\vim\ACM\对拍\mine.exe < D:\vim\ACM\对拍\data.txt > D:\vim\ACM\对拍\out1.txt
    D:\vim\ACM\对拍\std.exe < D:\vim\ACM\对拍\data.txt > D:\vim\ACM\对拍\out2.txt
    fc D:\vim\ACM\对拍\out1.txt D:\vim\ACM\对拍\out2.txt
if not errorlevel 1 goto loop  
pause 
goto loop
