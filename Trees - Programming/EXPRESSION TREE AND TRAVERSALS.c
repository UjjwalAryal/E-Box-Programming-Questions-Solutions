#include<stdio.h>
#include<stdlib.h>


struct tree
{
char data;
struct tree *left;
struct tree *right;
};

struct tree *stack[30];
int top=-1;

struct tree * newnode(char b);
void push(struct tree * temp);
struct tree * pop();
void inorder(struct tree * t);
void preorder(struct tree * t);
void postorder(struct tree * t);

int main()
{
char a[30];
struct tree * temp;
int i;
printf("Enter the postfix expression:\n");
scanf("%s",a);
for(i=0;a[i]!='\0';i++)
{
if(a[i]=='*' || a[i]=='/' || a[i]=='+' || a[i]=='-')
{
temp=newnode(a[i]);
temp->right=pop();
temp->left=pop();
push(temp);
}
else
{
temp=newnode(a[i]);
push(temp);
}
}
printf("Inorder Traversal");
inorder(temp);
  printf("\n");
printf("Preorder Traversal");
preorder(temp);
    printf("\n");
printf("Postorder Traversal");
postorder(temp);
return 0;
}


struct tree * newnode(char b){
    struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = b;
    nn->left = nn->right = NULL;
    return nn;
}
void push(struct tree * temp){
    stack[++top] = temp;
}

struct tree * pop(){
    return stack[top--];
}

void inorder(struct tree * t){
    if(t){
        inorder(t->left);
        printf(" %c",t->data);
        inorder(t->right);
    }
}


void preorder(struct tree * t){
    if(t){
        printf(" %c",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

void postorder(struct tree * t){
    if(t){
        
        postorder(t->left);
        postorder(t->right);
        printf(" %c",t->data);
    }
}
