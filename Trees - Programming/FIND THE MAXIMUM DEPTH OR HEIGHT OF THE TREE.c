#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct tree{
    int data;
    struct tree *right,*left;
};

struct queue{
    int front, rear;
    int size;
    struct tree* *array;
};

struct tree* newNode(int data);
struct queue* createQueue(int size);
void enqueue(struct tree *root, struct queue* queue);
struct tree* dequeue(struct queue* queue);
void insert(struct tree **root, int data, struct queue* queue);
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
 
 int max(int x, int y){
     return (x > y)? x : y;
 }

int height(struct tree* h){
    if(!h)
        return 0;
    return 1 + max(height(h->left), height(h->right));
}
int main()
{
    struct tree* root = NULL;
  char ans[3];
  int data;
    struct queue* queue = createQueue(100);
 do
 {
  printf("Enter the element to be inserted in the tree\n");
            scanf("%d",&data);          
        insert(&root, data, queue);
    printf("Do you want to insert another element?\n");
              scanf("%s",ans);
         } while (strcmp(ans,"yes") ==0); 
 
    printf("Hight of tree is %d",height(root));
      return 0;
}

struct tree* newNode(int data) {
    struct tree *nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = data;
    nn->right = nn->left = NULL;
    return nn;
}

struct queue* createQueue(int size){
    struct queue *nn = (struct queue*)malloc(sizeof(struct queue));
    nn->front = -1;
    nn->rear = 0;
    nn->size = size;
    nn->array = (struct tree**)malloc(size * sizeof(struct tree*));
    return nn;
}

int isEmpty(struct queue* q){
        return (q->front == -1 || q->rear == q->front);
}

struct tree* enquire(struct queue* nn){
    return nn->array[nn->rear];
}

void insert(struct tree **root, int data, struct queue* q){
    struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = data;
    nn->left = nn->right = NULL;
    enqueue(nn,q);
    
    if(isEmpty(q) && !(*root)){
        *root = nn;
    }
    else if(!(enquire(q)->left)){
        enquire(q)->left = nn;
    }else if(!(enquire(q)->right)){
        enquire(q)->right = nn;
        dequeue(q);
    }
}

void enqueue(struct tree *root, struct queue* nn){
    nn->front = (nn->front + 1) % nn->size; 
    nn->array[nn->front] = root;
}
 

struct tree* dequeue(struct queue* nn){
    struct tree* temp = nn->array[nn->rear];
    nn->rear = (nn->rear + 1) % nn->size;
    return temp;
}

void inorder(struct tree *temp) {
    if(temp){
        inorder(temp->left);
        printf(" %d",temp->data);
        inorder(temp->right);
    }
}

void preorder(struct tree *temp) {
    if(temp){
        printf(" %d",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
 

void postorder(struct tree *temp) {
    if(temp){
        postorder(temp->left);
        postorder(temp->right);
        printf(" %d",temp->data);
    }
}
