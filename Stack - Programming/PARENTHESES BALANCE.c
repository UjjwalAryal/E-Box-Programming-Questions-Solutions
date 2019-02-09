#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack {
    char *s;
    int top;
};
void initstack(struct stack * p){
    p->top = -1;
    p->s = (char *)malloc(128 * sizeof(char));
}
void push(struct stack *p, char item){
    p->s[++(p->top)] = item;
}

char pop(struct stack *p){
    return p->s[(p->top)--];    
}

void balancedornot(struct stack p, char *par){
    int i;
    initstack(&p);
    for(i = 0; i < strlen(par); i++){
        if(par[i] == ')'){
            if(pop(&p) != '('){
                printf("No\n");
                return;
            }
                
        }else if(par[i] == ']'){
            if(pop(&p) != '['){
                printf("No\n");
                return;
            }
        }else{
            push(&p, par[i]);
        }
    }
    printf("%s\n", (p.top == -1) ? "Yes" : "No");
}

int main(){
    int n;
    char s[100];
    scanf("%d",&n);
    
    struct stack st;
    
    while(n){
        scanf("%s",s);
        balancedornot(st, s);
        n--;
    }
    return 0;
}
