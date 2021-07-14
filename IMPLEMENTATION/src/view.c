#include"fun.h"
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
    scanf("%c",&b);
       printf("press any key to continue");
    scanf("%c",&c);
    menu();
}