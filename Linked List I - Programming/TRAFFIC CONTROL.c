#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct vehicle{
	int data;
	struct vehicle* link;
};
void append ( struct vehicle**, int ) ;
void display ( struct vehicle* ) ;
void reverse (struct vehicle**);

int main() {
	struct vehicle*p;
	p=NULL;
	int n,x=0;            
	do {
	printf("1.Insert\n2.Display\n3.Reverse\n4.Exit\n");
                	printf("Enter your choice :\n");
                	scanf("%d",&x);
	switch(x)
                 	{
                		case 1:
			printf("Enter the vehicle number\n");
			scanf("%d",&n);
			append(&p,n);
                			break;
                		case 2:
			if(p==NULL)
			{

				printf("Route is clear");
			}
			else
			{
				printf("The vehicles in the route are \n");
				display(p);
			}
                			printf("\n");
			break;	
                		case 3:
                
			if(p==NULL)
			{
				printf("There are no vehicle to redirect");
			}
			else
			{
				printf("The vehicles in the route after redirecting\n");
				reverse(&p);
				display(p);
			}
			printf("\n");
			break;
		case 4:
               			printf("Task accomplished\n");
			break;

	}} while(x!=4);

	return 0;
}


void append ( struct vehicle **q, int num ) {
    struct vehicle *nn = (struct vehicle*) malloc(sizeof(struct vehicle));
    struct vehicle *temp = *q;
    
	nn->link = NULL;
	nn->data = num;
	
	if(!(*q)){
	    *q = nn;
	    return;
	}
	
	while(temp->link){
	    temp = temp->link;
	}
	temp->link = nn;
}

void display ( struct vehicle *q ) {
    if(!q){
        printf("Route is clear\n");
        return;
    }
    // printf("The vehicles in the route are\n");
    while(q){
        printf("%d%s",q->data, (q->link) ? " " : "");
        q  =  q->link;
    }
}
void reverse ( struct vehicle **x ) {
    struct vehicle *head = *x, *temp, *prev = *x, *curr = *x;
    curr = curr->link;
    while(curr->link){
        temp = curr->link;
        curr->link = prev;
        prev = curr;
        curr = temp;
    }
    curr->link = prev;
    
    head->link = NULL;
    *x = curr;
}
