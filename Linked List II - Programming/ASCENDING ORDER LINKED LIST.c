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
void insert ( struct student **, struct student s ) ;
void display ( struct student * ) ;


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
		s.link=NULL;
		insert(&p,s);
                printf("Do you want to add details of another student? Type Yes/No\n");
		scanf("%s",ch);
	} while(!strcmp(ch,"Yes"));
	printf("The details of the students are\n");
        printf("%4s %10s %6s\n","ID","Name","Gender");
	display(p);
	return 0;
}


void insert ( struct student **q, struct student s ) {
	struct student *nn = (struct student *)malloc(sizeof(struct student));
	struct student *temp = *q;
	
	nn->id = s.id;
	strcpy(nn->name,s.name);
    strcpy(nn->gender, s.gender);
    nn->link = NULL;
    
    if(!temp){
        *q = nn;
        return;
    }
    
    if(s.id < temp->id){
        nn->link = temp;
        *q = nn;
        return;
    }
    
    while(temp->link && (s.id > temp->link->id)){
        temp = temp->link;
    }
    nn->link = temp->link;
    temp->link = nn;
}

void display ( struct student *q ) {
  struct student * temp=q;
  while(temp!=NULL)
  {
    printf("%4d ",temp->id);
    printf("%10s ",temp->name);
    printf("%6s ",temp->gender);
    printf("\n");
    temp=temp->link;
  }
}
