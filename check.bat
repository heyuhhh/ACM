::ע��ʹ��ansi���뱣��
@echo off  
:loop  
    D:\vim\ACM\����\maker.exe > D:\vim\ACM\����\data.txt
    D:\vim\ACM\����\mine.exe < D:\vim\ACM\����\data.txt > D:\vim\ACM\����\out1.txt
    D:\vim\ACM\����\std.exe < D:\vim\ACM\����\data.txt > D:\vim\ACM\����\out2.txt
    fc D:\vim\ACM\����\out1.txt D:\vim\ACM\����\out2.txt
if not errorlevel 1 goto loop  
pause 
goto loop
