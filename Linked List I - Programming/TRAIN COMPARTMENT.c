#include<stdio.h>
#include<stdlib.h>
struct compartment
{
int number;
struct compartment * link;
};
void append (struct compartment **q,int n);
void display(struct compartment *q);
void merge(struct compartment **p,struct compartment **q);
int main()
{
	int n,choice=1;
	struct compartment *list1;
	struct compartment *list2;
	list1 = NULL;
	list2 = NULL;
while(choice!=6)
{
	printf("1.Insert compartment in the first track\n2.Insert compartment in the second track\n3.Display track 1\n4.Display track 2\n5.Merge compartments\n6.Exit\nEnter your choice\n");
	scanf("%d",&choice);
switch(choice){
case 1:
	printf("Enter the compartment number\n");
	scanf("%d",&n);
	append(&list1,n);
	break;
case 2:
	printf("Enter the compartment number\n");
	scanf("%d",&n);
	append(&list2,n);
	break;
case 3:
	display(list1);
	break;
case 4:
	display(list2);
	break;
case 5:
	 merge(&list1,&list2);
	break;
case 6:
	printf("Exit\n");
	}
}
	return 0;
}
void append (struct compartment **q,int n){
    	struct compartment *temp = *q, *nn = (struct compartment*) malloc(sizeof(struct compartment));
    	nn->number = n;
        if(!(*q)){
            *q = nn;
            nn->link = NULL;
            return;
        }
    	while(temp->link && temp->link->number < n)
    	    temp = temp->link;
    	    
    	nn->link = temp->link;
    	temp->link = nn;
}
void display(struct compartment *q){
    if(!q){
        printf("Track is Empty\n");
        return;
    }
    printf("Compartments are:");
    while(q){
        printf("%d ",q->number);
        q = q->link;
    }printf("\n");
}

void merge(struct compartment **p,struct compartment **q){
    if(!(*p) && !(*q)){
        printf("No compartments were found.File complaint to railway enquiry\n");
        return;
    }
    struct compartment *head, *temp;
    
    if((*p) && (*q)){
        head = (*p)->number < (*q)->number ? *p : *q;
        if(*p == head)
            *p = (*p)->link;
        else
            *q = (*q)->link;
    }else if(*q){
        head = *q;
        *q = (*q)->link;
    }else if(*p){
        head = *p;
        *p = (*p)->link;
    }
    temp = head;
        
    while((*p) && (*q)){
            if((*p)->number < (*q)->number){
                temp->link = *p;
                *p = (*p)->link;
            }else{
                temp->link =  *q;
                *q = (*q)->link;
            }
            temp = temp->link;
    }
    while(*p){
        temp->link = *p;
        *p = (*p)->link;
        temp = temp->link;
    }
    while(*q){
        temp->link = *q;
        *q = (*q)->link;
        temp = temp->link;
    }
    
    display(head);
}
