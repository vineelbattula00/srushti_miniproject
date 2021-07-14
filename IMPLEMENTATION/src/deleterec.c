#include"fun.h"
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