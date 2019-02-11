#include<stdio.h>
#include<stdlib.h>
struct cabin
{
	int number;
	struct cabin * link;
};
void append (struct cabin **q,int n);
void display(struct cabin *q);
void rotateRight(struct cabin **q,int n);
void rotateleft(struct cabin **q,int n);
int main()
{
	int n,choice;
	struct cabin *list;
	list = NULL;
while(choice!=5)
{
	printf("1.Insert cabin\n2.Display\n3.Rotate Right\n4.Rotate Left\n5.Exit\n");
	printf("Enter your choice\n");
	scanf("%d",&choice);
switch(choice)
{
case 1:
	printf("Enter the cabin number\n");
	scanf("%d",&n);
	if(n>0 && n<100)
	append(&list,n);
	else
	printf("Invalid cabin number");
break;
case 2:
	display(list);
break;
case 3:
	printf("Enter the cabin number to rotate\n");
	scanf("%d",&n);
	rotateRight(&list,n);
break;
case 4:
	printf("Enter the cabin number to rotate\n");
	scanf("%d",&n);
	rotateleft(&list,n);

	break;
case 5:
    printf("Exit\n");
break;
}
}
	return 0;
}

int validate(struct cabin **q,int num){
    struct cabin *temp = *q;
	while(temp){
	    if(temp->number == num)
	        return 1;
	    temp = temp->link;
	}
	return 0;
}

void append (struct cabin **q,int n)
{
    // printf("append");

	
}
void display(struct cabin *q){
    if(q) 
        printf("Cabin positions are:");
    struct cabin *h = q;
    int flag = 1;
    while(h){
        printf("%d ",h->number);
        h = h->link;
        flag = 0;
    }
    if(flag)
        printf("No cabins were inserted\n");
    else
        printf("\n");
}

void rotateRight(struct cabin **q,int n){
    // printf("IN Rrotation");
    if(!(*q)){
        printf("No cabins were inserted\n");
        return;
    }
    if(!validate(q, n)){
        printf("Enter a valid cabin number\n");
        return;
    }
    if((*q)->number == n){
        printf("Number of rotation = 0\n");
        display(*q);
        return;
    }
    struct cabin *temp, *h = *q;
    int count = 0;
    
	while((*q)->link->number != n){
	    *q = (*q)->link;
	    count++;
	}
	
	temp = (*q)->link;
	(*q)->link = NULL;
	(*q) = temp;
    
    while(temp->link)
        temp = temp->link;
    temp->link = h;
    
    printf("Number of rotation = %d\n",++count);
    display(*q);
}


void rotateleft(struct cabin **q,int n){
    // printf("In Lrotation");
    if(!(*q)){
        printf("No cabins were inserted\n");
        return;
    }
    if((*q)->number == n){
        printf("Number of rotation = 0\n");
        display(*q);
        return;
    }

	if(!validate(q,n)){
	    printf("Enter a valid cabin number\n");
	    return;
    }
    
    struct cabin *temp, *h = *q;
    int count = 0;
    
    while((*q)->link->number != n){
        *q = (*q)->link;
    }
    temp = (*q)->link;
    (*q)->link = NULL;
    *q = temp;
    
    while(temp->link){
        temp = temp->link;
        count++;
    }
    temp->link = h;
    printf("Number of rotation = %d\n",++count);
    display(*q);
}
