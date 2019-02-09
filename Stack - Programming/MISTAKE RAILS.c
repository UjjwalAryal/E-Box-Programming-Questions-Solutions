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

void display(struct stack p){
    if(p.top == -1){
        printf("Empty\n");
        return;
    }
    int i;
    for(i = p.top; i >=0 ; i--)
        printf("%d ",p.a[i]);
    printf("\n");
}

void marshal(int n){
    int temp, c, i, a[n];
    struct stack res, s, dummy;
    
    while(1){
        initstack(&s, n);
        initstack(&res, n);
        initstack(&dummy, n);
        
        for(i = n; i > 0; i--){
            push(&s, i);
        }
        scanf("%d",&a[0]); 
        if(!a[0])
            return;          
      
        for(i = 1; i < n; i++)
            scanf("%d",&a[i]);
        
        for(i = n - 1; i >= 0; i--)
            push(&res,a[i]);

        while(!isEmpty(&s) || !isEmpty(&res)){

        temp = pop(&res);

            while(!isEmpty(&s) && (c = pop(&s)) != temp){
                // c = pop(&s);
                push(&dummy, c);
            }
            while(!isEmpty(&res) && !isEmpty(&dummy) && peep(&res)==peep(&dummy)){
                pop(&res);
                pop(&dummy);
            }
            
        }
        printf("%s\n",isEmpty(&dummy)? "Yes" : "No");
         
     }
    
}
int main(){
    
    int n;
    scanf("%d",&n);
    marshal(n);
    return 0;
}
