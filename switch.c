void main()
{
    int choice;

    clrscr();

    printf("CPU SCHEDULING\n");
    printf("--------------------\n");
    printf("1. FCFS\n");
    printf("2. Round Robin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            fcfs();
            break;

        case 2:
            roundrobin();
            break;

        default:
            printf("\nInvalid Choice!");
    }
}