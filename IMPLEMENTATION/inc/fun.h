#ifndef __FUN_H
#define __FUN_H

#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
//#include<windows.h>
#include<string.h>

void gotoxy(int ,int );
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct employee
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};

#endif