#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int MAX=50;
struct postfix{
       int stack[50];
        int top,nn;
      char *s;
};
    void initpostfix(struct postfix *);
     void setexpr(struct postfix *, char *str);
     void push(struct postfix *, int item);
     int pop(struct postfix *);
     void calculate(struct postfix *);
     void show(struct postfix );

int main()
{
    char expr[50];
    printf("Enter postfix expression to be evaluated:\n");
    scanf("%s",expr);
    struct postfix p;
    initpostfix(&p);
    setexpr(&p,expr);
    calculate(&p);
    show(p);
    return 0;
}

void initpostfix(struct postfix *p){
    p->top = -1;
}

void setexpr(struct postfix *p, char *str){    
    p->s = (char*)malloc(1000*sizeof(char));
    strcpy(p->s, str);
}

void push(struct postfix *p, int item){   
    p->stack[++p->top] = item;
}
int pop(struct postfix *p){  
    return p->stack[p->top--];

}
void calculate(struct postfix *p){
    int i, t1, t2;
    while(*(p->s)){
       i = 0;
        if(isdigit(p->s[i]))
            push(p, (int)(p->s[i] - '0'));
        else{
            t2 = pop(p);
            t1 = pop(p);  
            if(p->s[i]=='+')
                p->nn = t1 + t2;
            else if(p->s[i]=='-') 
                p->nn  = t1 - t2;
            else if(p->s[i]=='/')
                p->nn = t1 / t2;
            else if(p->s[i] == '*')
                p->nn = t1 * t2;
            push(p, p->nn);  
        } 
        (p->s) += sizeof(char);
    }
}
void show(struct postfix p){  
    printf("Result is: %d",p.stack[p.top]);
}
