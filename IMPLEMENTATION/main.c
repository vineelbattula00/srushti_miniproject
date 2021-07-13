#include"fun.h"
#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int main()
{
    gotoxy(15,8);
    printf("<--:employee_record_system:-->");
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
