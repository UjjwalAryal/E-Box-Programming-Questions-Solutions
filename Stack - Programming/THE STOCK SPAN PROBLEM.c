#include<stdio.h>
#include<stdlib.h>

struct stack{
    int *a;
    int maxSize;
    int top;
};

void initstack(struct stack *p, int maxSize){
    p->maxSize = maxSize;
    p->a =(int *)malloc(maxSize * sizeof(struct stack));
    p->top = -1;
}

void push(struct stack *p, int item){
    if(p->top == (p->maxSize - 1)){
        return;
    }
    p->a[++(p->top)] = item;
}

int pop(struct stack *p){
    if(p->top == -1){
        return -1000;
    }
    return p->a[p->top--]; 
}

int peep(struct stack *p){
    if(p->top == -1){
        return -1000;
    }
    return p->a[p->top]; 
}

int isEmpty(struct stack *p){
    return (p->top == -1);
}

void calculateSpan(int *price, int n, int *span){
    span[0] = 1;
    struct stack s;
    initstack(&s, n);
    push(&s,0);
    int i;
    for(i = 1; i < n; i++){
        while(!isEmpty(&s) && price[peep(&s)] <= price[i]){
            pop(&s);
        }
        
        span[i] = isEmpty(&s) ? i + 1 : (i - peep(&s));
        push(&s, i);
    }
}

void printSpan(int *span, int n){
    int i;
    for(i = 0; i< n; i++) printf("%d ",span[i]);
}

int main(){
    int n;
    printf("Enter the number of days\nEnter the stock prices\n");
    scanf("%d",&n);
    int i, a[n], span[n];
    
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("Span values\n");

    calculateSpan(a,n,span);
    
    printSpan(span,n);
    return 0;
}
