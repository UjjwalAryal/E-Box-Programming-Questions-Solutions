#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct software {
	char name[15];
	int memory;
	struct software * link;
};
void append ( struct software **,char[] ,int ) ;
void display ( struct software * ) ;
void findmin (struct software *);

int main() {
	struct software *p ;
	p=NULL;
	int n;
	char ch[10];
	int choice=1;
while(choice>=1 && choice<4)
{
	printf("1.Insert new software\n2.Display all the softwares\n3.Get the minimum memory software\n4.Exit\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("Enter the software name\n");
			scanf("%s",ch);
			do{
			printf("Enter the memory used\n");
			scanf("%d",&n);
			}while(n==0);
			append(&p,ch,n);
			break;
		case 2:
			display(p);
			break;
		case 3:
			findmin(p);
			break;
		case 4:
			printf("Exit\n");
			break;
		}
	}
	return 0;
}

void append ( struct software **q, char sname[15] ,int num ) {
    struct software *nn = (struct software*) malloc(sizeof(struct software));
    struct software *temp = *q;
    
	nn->link = NULL;
	nn->memory = num;
	strcpy(nn->name, sname);
	
	if(!(*q)){
	    *q = nn;
	    return;
	}
	
	while(temp->link){
	    temp = temp->link;
	}
	temp->link = nn;
}

void display ( struct software *q ) {
    if(!q){
        printf("Software list is empty\n");
        return;
    }
    printf("Software list:\n");
    int i = 1;
    while(q){
        printf("%d) %s %d\n",i++,q->name,q->memory);
        q  =  q->link;
    }
}

void findmin ( struct software *q ) {
    if(!q){
        printf("Software list is empty\n");
        return;
    }
    int min_ = 9999;
    char temp[15];
    while(q){
        if(q->memory < min_){
            strcpy(temp,q->name);
            min_ = q->memory;
        }
        q = q->link;
    }
    printf("Minimum memory Software is:\n%s %d\n",temp,min_);
}
