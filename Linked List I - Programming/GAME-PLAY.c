#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process {
	int memory;
	struct process * link;
};
void append ( struct process **, int ) ;
void display ( struct process * ) ;
void findmax (struct process *);

int main() {
	struct process *p ;
	p=NULL;
	int n;
	int ch=1;
while(ch>=1 && ch<4)
{
	printf("1.Insert new process memory usage\n2.Display all the memory usage\n3.Get the maximum memory\n4.Exit\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("Enter the memory usage\n");
			scanf("%d",&n);
			append(&p,n);
			break;
		case 2:
			display(p);
			break;
		case 3:
			findmax(p);
			break;
		case 4:
			printf("Exit\n");
			break;
		}
	}
	return 0;
}


void append ( struct process **q, int num ) {
    struct process *nn = (struct process*) malloc(sizeof(struct process));
    struct process *temp = *q;
	nn->link = NULL;
	nn->memory = num;
	if(!(*q)){
	    *q = nn;
	    return;
	}
	
	while(temp->link){
	    temp = temp->link;
	}
	temp->link = nn;
}

void display ( struct process *q ) {
    if(!q){
        printf("Memory usage list is empty\n");
        return;
    }
    printf("Memory usage list:\n");
    while(q){
        printf("%d%s",q->memory, (q->link) ? " " : "");
        q  =  q->link;
    }
    printf("\n");
}

void findmax ( struct process *q ) {
    if(!q){
        printf("Memory usage list is empty\n");
        return;
    }
    int max_ = -9999;
    while(q){
        max_ = (max_ < q->memory) ? q->memory : max_;
        q = q->link;
    }
    printf("Maximum memory used : %d\n",max_);
}
