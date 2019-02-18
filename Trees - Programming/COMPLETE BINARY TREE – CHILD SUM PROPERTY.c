#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *right,*left;
};

struct queue
{
    int front, rear;
    int size;
    struct tree* *array;
};

struct tree* newNode(int data);
struct queue* createQueue(int size);
void enqueue(struct tree *root, struct queue* queue);
struct tree* dequeue(struct queue* queue);
void insert(struct tree **root, int data, struct queue* queue);
void levelOrder(struct tree* root);
int isSumProperty(struct tree* node); 
void inorder(struct tree *temp) ;

int main()
{
    struct tree* root = NULL;
  int data;
    struct queue* queue = createQueue(1000);
    int i,n;
  printf("Enter the number of elements in the tree\n");
 scanf("%d",&n);
  printf("Enter the elements in the tree\n");
    for(i = 1; i <= n; ++i)
    {
      scanf("%d",&data);
        insert(&root, data, queue);
    }
  printf("The elements in the tree in level order are");
  levelOrder(root);
  printf("\n");
 
if(isSumProperty(root))
    printf("The tree satisfies the children sum property ");
  else
    printf("The tree does not satisfy the children sum property ");
 
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
        return (q->rear > q->front);
}

struct tree* enquire(struct queue* nn){
    return nn->array[nn->rear];
}

void insert(struct tree **root, int data, struct queue* q){
    struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = data;
    nn->left = nn->right = NULL;
    enqueue(nn,q);
    
    if(!(*root)){
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


void levelOrder(struct tree* root){
     struct queue* Q = createQueue(1000);
     struct tree* temp;
     if(root) enqueue(root, Q);
     while(!isEmpty(Q)){
         temp = dequeue(Q);
         printf(" %d",temp->data);
         if(temp->left)
            enqueue(temp->left, Q);
         if(temp->right)
            enqueue(temp->right, Q);
     }
}
 
int isSumProperty(struct tree* node){
    static int res = 1;
    if(node){
        isSumProperty(node->left);
        if(node->left || node->right)
            res &= (node->data  == (node->left ? node->left->data : 0) + (node->right ? node->right->data: 0));       
        isSumProperty(node->right);
    }
    return res;
}
