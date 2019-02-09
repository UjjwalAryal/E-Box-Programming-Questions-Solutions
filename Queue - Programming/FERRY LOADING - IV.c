#include<stdio.h>
#include<stdlib.h>

struct node {
    int data ;
    char d;
    struct node * link ;
};

struct Queue{
    struct node *front, *rear;
};

void initQueue(struct Queue *Q){
        (Q)->front = (Q)->rear = NULL;
}

void enQueue(struct Queue *Q, int ele){
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = ele;
    
    if(!(Q->front)){
        Q->rear = Q->front = nn->link = nn;
        return;
    }
    nn->link = Q->front;
    Q->rear->link = nn;
    Q->rear = nn;
}

int isEmpty(struct Queue Q){
    if(Q.front)
        return 0;
    return 1;
}

struct node deQueue(struct Queue *Q){
    struct node ret;
    
    if(!(Q->front)){
        return ret;
    }    
    
    ret.data = Q->front->data;
    ret.d = Q->front->data;
    
    if(Q->front->link == Q->front){
        Q->rear = Q->front = NULL;
    }
    else{
        Q->front = Q->front->link;
        Q->rear->link = Q->front;
    }
    return ret;
}

struct node enquire(struct Queue Q){
    struct node ret;
    ret.data = Q.front->data;
    ret.d = Q.front->d;
    return ret;

}

int main(){
    int l, m, temp;
    char s_temp[1000];
    scanf("%d%d",&l,&m);
    struct Queue Q[2];
    l *= 100;
    
    initQueue(&Q[0]);
    initQueue(&Q[1]);
    
    while(m--){
        scanf("%d %s",&temp, s_temp);
        if(s_temp[0] == 'l')
            enQueue(&Q[0], temp);
        else
            enQueue(&Q[1], temp);
    }

    int curl, count = 0, curr = 0;
    
    while(!(isEmpty(Q[0]) && isEmpty(Q[1]))){
        curl = 0;
        
        while(!isEmpty(Q[curr]) && (curl + enquire(Q[curr]).data) <= l){
                curl += enquire(Q[curr]).data;    
                deQueue(&Q[curr]);
            }
            
        curr = (curr == 0) ? 1 : 0;
        count++;
    }
    printf("The number of times the ferry has to cross the river\n%d",count);
    return 0;
}
