#include"fun.h"
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
