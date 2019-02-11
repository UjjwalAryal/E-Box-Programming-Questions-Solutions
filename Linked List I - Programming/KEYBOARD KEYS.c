#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct keyboard {
	int key;
	struct keyboard * link;
};
void insert ( struct keyboard **, int ) ;
void display ( struct keyboard * ) ;


int main() {
	struct keyboard *p ;
	p=NULL;
	int keys,choice=1;
	
while(choice<3){
	printf("1.Enter a disassembled key\n2.View keyboard\n3.Exit\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
	do{
		printf("Enter the key number\n");
		scanf("%d",&keys);
		}while(keys>0 && keys >9);
		insert(&p,keys);
		break;
	case 2:
		display(p);
		break;
	case 3:
		printf("Exit\n");
		break;
}
}
	return 0;
}

void insert (struct keyboard **q,int n){

}

void display(struct keyboard *q){
    if(!q){
        printf("Keyboard has no disassembled key\n");
        return;
    }
    printf("Keyboard:\n");
    while(q){
        printf("%d ",q->key);
        q = q->link;
    }printf("\n");
}
