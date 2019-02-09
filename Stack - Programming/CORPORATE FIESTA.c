#include<stdio.h>
#include<stdlib.h>

struct node { 
    int data ;
    int next;
    struct node * link ;
} ;

void push(struct node **s, int n){
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = n;
    nn->link = *s;
    *s = nn;
}


void display(struct node *s){
    while(s){
        printf("%d ",s->data);
        s = s->link;
    }
    printf("\n");
}

int pop (struct node **s){
    if(!(*s)){
        return -1;
    }
    int temp = (*s)->data;
    *s = (*s)->link;
    return temp;
}

int main(){
    int n, id;
    char choice;
    struct node *s = NULL;
    
    scanf("%d%d",&n,&id);
    push(&s,id);
    while(n--){
        scanf("\n%c",&choice);
        if(choice == 'F'){
            scanf("%d",&id);
            push(&s, id);
        }
        else{
            int temp1 = pop(&s);
            int temp2 = pop(&s);
            push(&s,temp1);
            push(&s,temp2);
            // pop(&s);
        }
        
    }
    printf("Player %d", pop(&s));
    return 0;
}
