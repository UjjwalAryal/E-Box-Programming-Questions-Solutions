#include<stdio.h>
#include<stdlib.h>
struct special_mantra
{
int data;
int position;
struct special_mantra* link;
};
void append (struct special_mantra**q,int n);
void displayData(struct special_mantra*q);
void sort(struct special_mantra**q, int l, int h);
int main()
{
	int n,choice=0,start,end;
	struct special_mantra *list;
	list = NULL;
while(choice!=4){
printf("1.Insert\n2.Display\n3.Sort\n4.Exit\n");
printf("Enter the choice\n");
scanf("%d",&choice);
switch(choice){
case 1:
		printf("Enter the value\n");
		scanf("%d",&n);
		append(&list,n);
break;

case 2:
	displayData(list);
break;
case 3:
	printf("Enter the starting position\n");
	scanf("%d",&start);
	printf("Enter the ending position\n");
	scanf("%d",&end);
	sort(&list,start,end);
	displayData(list);
break;
case 4:
		printf("Exit\n");
break;
}
}
	return 0;
}
void append (struct special_mantra **q,int n)
{
    static int pos = 0;
    
    struct special_mantra *nn = (struct special_mantra*) malloc(sizeof(struct special_mantra));
    struct special_mantra *temp = *q;
	nn->link = NULL;
	nn->data = n;
	nn->position = ++pos; 
	if(!(*q)){
	    *q = nn;
	    return;
	}
	
	while(temp->link){
	    temp = temp->link;
	}
	temp->link = nn;
}

void displayData(struct special_mantra *q){
    struct special_mantra *h = q;
    printf("The elements in the linked list are ");
    while(q){
        printf("%d ",q->data);
        q=q->link;
    }
    printf("\n"); 
    
    if(!h)
        printf("List is empty\n");
}

struct special_mantra* max_index(struct special_mantra *q, int l, int h){
    int max_ = -99999;
    struct special_mantra *hh;
    while(q){
        if(((q->position)<l || (q->position)>h) && (max_ < q->data)){
            max_ = q->data;
            hh = q;
        }
        q = q->link;
    }
    return hh;
}

struct special_mantra* min_index(struct special_mantra *q, int l, int h){
    int min_ = 99999;
    struct special_mantra *hh;
    while(q){
        if(((q->position)>=l) && ((q->position)<=h) && (min_ > q->data)){
            min_ = q->data;
            hh = q;
        }
        q = q->link;
    }
    return hh;
}

int isValid(struct special_mantra *q, int l, int h){
    int res = (l > 0) && (h>0);
    do{
        q = q->link;
    }while(q->link);
    return (l<= q->position && (h <= (q->position)) && res);
}

void sort(struct special_mantra **qq, int l, int h){
    struct special_mantra *q = *qq;
    if((!q) || (l>=h) || !isValid(q,l,h)){
        printf("List is empty or Invalid index\n");
        return;
    }
    if(!(q->link))
        return;
    int t, i = 1;
    struct special_mantra* temp;
    while(q){
        if(i<l || i>h)
            temp = max_index(q,l,h);
        else
            temp = min_index(q,l,h);
        
        t = temp->data;
        temp->data = q->data;
        q->data = t;
        
        q= q->link;
        i++;
    }
}
