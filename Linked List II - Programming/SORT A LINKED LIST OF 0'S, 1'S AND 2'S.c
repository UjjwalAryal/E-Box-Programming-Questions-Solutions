#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
	int data;
	struct node * link;
};
void append ( struct node **, int ) ;
void display ( struct node * ) ;
void sort(struct node *head);

int main() {
	struct node *p ;
	p=NULL;
	int n;
	char ch[10];
	do {
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&p,n);
		printf("Do you want to add another node? Type Yes/No\n");
		scanf("%s",ch);
	}while(!strcmp(ch,"Yes"));
	printf("The elements in the linked list are ");
	display(p);
	printf("\n");
        sort(p);
	printf("The elements in the linked list after sorting are ");
	display(p);
	printf("\n");
	return 0;
}

void append ( struct node **q, int num ){
    struct node *temp =  *q, *nn = (struct node *)malloc(sizeof(struct node));
	nn->data = num;
	nn->link = NULL;
	
	if(!(*q)){
	     *q = nn;
	     return;
	}
	
	while(temp->link)   
	    temp = temp->link;
	temp->link = nn;
}

void display ( struct node *q ){
  struct node *temp=q;
  while(temp!=NULL)
  {
    printf("%d ",temp->data);
    temp=temp->link;
  }
}

void sort(struct node *head){     // O(n) algorithm for sorting linked list with 0's, 1's and 2's.
    int i = 1, curr = 0, count[3] = { 0 };
    struct node* head_ = head;
    
    while(head){
        count[head->data] += 1;
        head = head->link;
    }
    count[1] += count[0]; 
    count[2] += count[1];
    // printf("%d  %d  %d**\n",count[0],count[1],count[2]);
    
    head = head_;
    while(head){
        if(i>count[1])
            curr = 2;
        else if(i>count[0])
            curr = 1;        
            
        head->data = curr;
        head = head->link;
            
        i++;
    }
    
}
