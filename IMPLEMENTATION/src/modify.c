#include"fun.h"
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