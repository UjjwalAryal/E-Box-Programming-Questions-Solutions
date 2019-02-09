void printMenu(){
    printf("Choice 1 : Enter element into Queue\nChoice 2 : Delete element from Queue\nChoice 3 : Display\nAny other choice : Exit\n");
}

int main(){
    int n, choice;
    struct node *front = NULL, *rear = NULL;
    do{
        printMenu();
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the element to be inserted/entered\n");
                scanf("%d",&n);
                addcirq(&front, &rear, n);
            break;
            case 2:
                n = delcirq(&front, &rear);
                if(n != -1000)
                    printf("The deleted element is %d\n",n);
            break;
            case 3:
                printf("The contents of the queue are");
                cirq_display(front);
            break;
        }
    }while(choice > 0 && choice < 4);
    
    return 0;
}
