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