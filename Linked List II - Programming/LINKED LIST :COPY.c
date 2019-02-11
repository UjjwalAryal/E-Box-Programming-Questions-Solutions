#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
  int id;
  char name[10];
  char gender[10];
  struct student * link;
};
void append ( struct student **, struct student ) ;
void display ( struct student * ) ;
struct student *copy(struct student *);

int main() {
        struct student *p ;
	struct student s ;
	struct student *z ;
	p=NULL;
        z=NULL;
	char ch[10];
	do {
		printf("Enter the id\n");
		scanf("%d",&s.id);
                printf("Enter the name\n");
		scanf("%s",s.name); 
		printf("Enter the gender\n");
		scanf("%s",s.gender);
                s.link = NULL;
		append(&p,s);
                printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	printf("The details of the students are\n");
	printf("%4s %10s %7s\n","ID","Name","Gender");
	display(p);
        z=copy(p);
	printf("The details of the students after copying are\n");
	printf("%4s %10s %7s\n","ID","Name","Gender");
	display(z);
	return 0;
}

void append ( struct student **q, struct student s ){
    struct student *temp =  *q, *nn = (struct student *)malloc(sizeof(struct student));
	nn->id = s.id;
	strcpy(nn->name,s.name);
	strcpy(nn->gender,s.gender);
	nn->link = NULL;
	
	if(!(*q)){
	     *q = nn;
	     return;
	}
	
	while(temp->link)   
	    temp = temp->link;
	temp->link = nn;
}

struct student * copy(struct student *q) {
    if(!q){
        return NULL;
    }
	struct student *curr, *head, *prev = malloc(sizeof(struct student));
	head = prev;
	
	prev->link = q->link;
	prev->id = q->id;
	strcpy(prev->name, q->name);
	strcpy(prev->gender,q->gender);
	
	q = q->link;
	
	while(q){
    	curr = malloc(sizeof(struct student));
    	curr->link = q->link;
    	curr->id = q->id;
    	strcpy(curr->name, q->name);
    	strcpy(curr->gender,q->gender);
    	q = q->link;
        prev->link = curr;
        prev = curr;
	}
	return head;
} 

void display ( struct student *q ){
  struct student *temp=q;
  while(temp!=NULL)
  {
    printf("%4d ",temp->id);
    printf("%10s ",temp->name);
    printf("%7s ",temp->gender);
    printf("\n");
    temp=temp->link;
  }
}
