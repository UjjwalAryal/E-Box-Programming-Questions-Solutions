#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct harry
{
    char data;
    struct harry* next;
};

struct harry* reverse(struct harry*);
bool compare(struct harry*, struct harry *);
bool isMagical(struct harry *head);
void display(struct harry *p);
 void insert(struct harry** head, char data);

int main() {
	struct harry *p ;
	p=NULL;
	int choice;
	char str;
while(choice!=4)
	{
	printf("1.Magical spell letter\n2.Display the Magical spell\n3.isMagical\n4.Exit\nEnter your choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter a Magical spell letter\n");
				scanf("\n%c",&str);
				insert(&p,str);
				break;
			case 2:
			    if(!p)
			        printf("There is no Magical spell\n");
				else{
				    display(p);
				    printf("\n");
				}
				break;
			case 3:
				isMagical(p)? printf("Magical Spell\n"):printf("Not a magical spell\n");
				break;
			case 4:
				printf("Exit\n");
				break;
			}
		}
	return 0;
}

bool isMagical(struct harry *head){
    struct harry *reverse_head = reverse(head);
    return compare(head, reverse_head);
}
 

struct harry* reverse(struct harry* head){
    struct harry *nn, *r_head = NULL;
    while(head){
        nn = (struct harry*)malloc(sizeof(struct harry));
        nn->next = r_head;
        nn->data = head->data;
        r_head = nn;
        head = head->next;
    }
    
    return r_head;
}
 

bool compare(struct harry* head1, struct harry *head2){
    int res = 1;
    while(head1 && head2){
        res &= (head1->data == head2->data);
        head1 = head1->next;
        head2 = head2->next;
    }
    return (res && !head1 && !head2);
}
 

 

void display(struct harry *p){
    if(p){
        display(p->next);
        printf("%c",p->data);
    }
}
