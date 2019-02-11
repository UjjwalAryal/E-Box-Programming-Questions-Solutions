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
void reverse (struct student **);

int main() {
	struct student *p ;
	p=NULL;
	struct student s;
        char ch[10];
	do {
		printf("Enter the id\n");
		scanf("%d",&s.id);
                printf("Enter the name\n");
		scanf("%s",s.name); 
		printf("Enter the gender\n");
		scanf("%s",s.gender);
		append(&p,s);
                printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
	printf("The details of the students are\n");
        printf("%4s %10s %6s\n","ID","Name","Gender");
	display(p);
	printf("The details of the students after reversing are\n");
        printf("%4s %10s %6s\n","ID","Name","Gender");
	reverse(&p);
	display(p);
	return 0;
}


void append ( struct student **q, struct student s ) {
    	struct student *temp = *q, *nn = (struct student*) malloc(sizeof(struct student));
    	strcpy(nn->name, s.name);
    	strcpy(nn->gender,s.gender);
    	nn->id = s.id;
    	nn->link = NULL;
        
        if(!(*q)){
            *q = nn;
            return;
        } 
    	while(temp->link)
    	    temp = temp->link;
    	    
        temp->link = nn;

}

void display ( struct student *q ) {
  struct student *temp = q;
  while(temp!=NULL)
  {
	    printf("%4d ",temp->id);
	    printf("%10s ",temp->name);
	    printf("%6s ",temp->gender);
        printf("\n");
    temp=temp->link;
  }
}


void reverse(struct student **x ) {
    struct student *head = *x, *temp, *prev = *x, *curr = *x;
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
