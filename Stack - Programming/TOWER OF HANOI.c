#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct stack{
    int *a;
    int top;
    int maxSize;
    char name;
};

void initstack(struct stack * p, int maxSize){
    p->top = -1;
    p->maxSize = maxSize;
    p->a = (int *)malloc(sizeof(int)*maxSize);
}

void push(struct stack *p, int item){
    if(p->top == p->maxSize-1)
        return;
    p->a[++(p->top)] = item;
}

int pop(struct stack * p){
    if(p->top == -1)
        return INT_MIN;
    int temp = p->a[p->top];
    p->top--;
    return temp;
}

void moveDisk(char fromPeg, char toPeg, int disk){
    printf("Move the disk %d from \'%c\' to \'%c\'\n",disk,fromPeg,toPeg);
}

void moveDisksBetweenTwoPoles(struct stack *src, struct stack *dest, char s, char d){
    int t1 = pop(src);
    int  t2 = pop(dest);
    if(t1 == INT_MIN){
        push(src,t2);
        moveDisk(d,s,t2);
    }else if(t2 == INT_MIN){
        push(dest,t1);
        moveDisk(s,d,t1);
    }
    else if(t1 > t2){
        push(src,t1);
        push(src,t2);
        moveDisk(d,s,t2);
    }else{
        push(dest,t2);
        push(dest,t1);
        moveDisk(s,d,t1);
    }
}

void hanoiIterative(int n, struct stack *src, struct stack *aux, struct stack *dest){
    int i;
    
    for(i = n; i > 0; i--)
            push(src, i);  
         
    char s = 'S', d = 'D', a = 'A';
    if(!(n&1)){
        char tt = d;      
        d = a;                 
        a = tt;          
    }

  
  for(i = 1; i < (1<<n); i++){
      if(i%3 == 1){
          moveDisksBetweenTwoPoles(src,dest,s,d);
      }else if(i%3==2){
          moveDisksBetweenTwoPoles(src,aux,s,a);
      }else{
          moveDisksBetweenTwoPoles(aux,dest,a,d);
      }
  }
  
    // if(n){
    //     hanoiIterative(n-1, src, dest, aux);
    //     moveDisksBetweenTwoPoles(src,dest,src->name,dest->name);
    //     hanoiIterative(n-1,aux,src,dest);
    // }
  
}

int main(){
    int  n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    struct stack src, aux, dest;

    initstack(&src, n);
    initstack(&aux, n);
    initstack(&dest, n);
    hanoiIterative(n, &src, &aux, &dest);
    return 0;
}
