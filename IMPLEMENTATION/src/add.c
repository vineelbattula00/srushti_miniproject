#include"fun.h"
#include<stdio.h>
void add()
{
    FILE *fp;
    struct employee std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        
        printf("<--:ADD RECORD:-->");
        
        printf("Enter details of employee.");
        
        printf("Enter Name : ");
//        gets(std.name);///???
        scanf("%s",std.name);
        
        printf("Enter Mobile Number : ");
        scanf("%s",std.mobile);
        
        printf("Enter employee id no : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        
        printf("Enter Designation : ");
//        gets(std.course);///???
        scanf("%s",std.course);
        
        printf("Enter Branch : ");
        scanf("%s",std.branch);
//        
//        printf("Enter Father's Name : ");
//        gets(std.fathername);
        fwrite(&std,sizeof(std),1,fp);
        
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
        char a;
        another = scanf("%c",&a);
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    
    char b,c;
    scanf("%c",&b);
    printf("Press any key to continue.");
    scanf("%c",&c);
    menu();
}