//employment record system

#include<stdio.h>

#include<stdlib.h>
#include<windows.h>
#include<string.h>
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
int main()
{ 
    char a, b;
    printf("<--:employee Record Management System:-->");
    scanf("%c",&a);
    printf("Press any key to continue.");
    scanf("%c",&b);
    
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    
    printf("<--:MENU:-->");
    
    printf("Enter appropriate number to perform following task.");
   
    printf("1 : Add Record.");
    
    printf("2 : View Record.");
    
    printf("3 : Search Record.");
   
    printf("4 : Modify Record.");
    
    printf("5 : Delete.");
   
    printf("6 : Exit.");
    
    printf("Enter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        
        printf("Invalid Choice.");
    }
}
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
//        scanf("%s",std.fathername);
        fwrite(&std,sizeof(std),1,fp);
        
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
//        another = getch();///???
    char a;
        another = scanf("%c",&a)
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    char b, c;
    scanf("%c",&b)
    printf("Press any key to continue.");
    scanf(&c)
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct employee std;
    system("cls");
    
    printf("<--:VIEW RECORD:-->");
    
    printf("S.No   Name of employee       Mobile No   Employment ID No  Course      Branch");
    
    printf("--------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        
        printf("%-7d%-22s%-12s%-9d%-12s%-12s",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    char b,c;
    scanf("%c",&b)
    printf("Press any key to continue.");
    scanf("%c",&c);
    menu();
}
void search()
{
    FILE *fp;
    struct employee std;
    char stname[20];
    system("cls");
    
    printf("<--:SEARCH RECORD:-->");
    
    printf("Enter name of employee : ");
    fflush(stdin);
    scanf("%s",stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            
            printf("Name : %s",std.name);
          
            printf("Mobile Number : %s",std.mobile);
           
            printf("employee id no : %d",std.rollno);
            
            printf("Course : %s",std.course);
            
            printf("Branch : %s",std.branch);
        }
    }
    fclose(fp);
    char b,c;
    scanf("%c",&b);
    printf("Press any key to continue.");
    scanf("%c",&c);
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct employee std;
    system("cls");
    
    printf("<--:MODIFY RECORD:-->");
    
    printf("Enter name of employee to modify: ");
    fflush(stdin);
    scanf("%s",stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            
            printf("Enter name: ");
            scanf("%s",std.name);
            
            printf("Enter mobile number : ");
            scanf("%s",std.mobile);
            
            printf("Enter employee id no : ");
            scanf("%d",&std.rollno);
            
            printf("Enter Course : ");
            fflush(stdin);
            scanf("%s",std.course);
            
            printf("Enter Branch : ");
            fflush(stdin);
            scanf("%s",std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    char b,c;
    scanf("%c",&b);
    printf("Press any key to continue.");
    scanf("%c",&c);
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct employee std;
    system("cls");
    
    printf("<--:DELETE RECORD:-->");
    
    printf("Enter name of employee to delete record : ");
    fflush(stdin);
    scanf("%s",stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    char b,c;
    scanf("%c",&c);
    printf("Press any key to continue.");
    scanf("%c",&b);
    menu();
}
