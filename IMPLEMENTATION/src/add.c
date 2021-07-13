#include"fun.h"
void add()
{
    FILE *fp;
    struct employee std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of employee.");
        gotoxy(10,7);
        printf("Enter Name : ");
//        gets(std.name);///???
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter employee id no : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Designation : ");
//        gets(std.course);///???
        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(std.branch);
//        gotoxy(10,12);
//        printf("Enter Father's Name : ");
//        gets(std.fathername);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}