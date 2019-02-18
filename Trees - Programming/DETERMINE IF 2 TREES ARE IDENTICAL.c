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

void enqueue(struct tree *root, struct queue* nn){
    nn->front = (nn->front + 1) % nn->size; 
    nn->array[nn->front] = root;
}
 

struct tree* dequeue(struct queue* nn){
    struct tree* temp = nn->array[nn->rear];
    nn->rear = (nn->rear + 1) % nn->size;
    return temp;
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


void inorder(struct tree *temp) {
    if(temp){
        inorder(temp->left);
        printf(" %d",temp->data);
        inorder(temp->right);
    }
}

int identicalTrees(struct tree *a, struct tree *b){


    //  struct queue* Q[2]; struct tree *t[2]; t[0] = a; t[1] = b;          //Solution #1, Check whether the level order traversal is same or not.
    //  Q[0] = createQueue(100);
    //  Q[1] = createQueue(100);
    //  int res = 1;
    //  struct tree* temp[2];
    //  if(t[0]) enqueue(t[0], Q[0]);
    //  if(t[1]) enqueue(t[1], Q[1]);
     
    //  while(!isEmpty(Q[0]) && !isEmpty(Q[1]) && res){
    //      temp[0] = dequeue(Q[0]);
    //      temp[1] = dequeue(Q[1]);
         
    //      res &= (temp[0] && temp[1]) ? (temp[0]->data == temp[1]->data) : 0;
    //      if(temp[0] && temp[1]){ 
    //          if(temp[0]->left)
    //             enqueue(temp[0]->left, Q[0]);
    //          if(temp[0]->right)
    //             enqueue(temp[0]->right, Q[0]);

    //          if(temp[1]->left)
    //             enqueue(temp[1]->left, Q[1]);
    //          if(temp[1]->right)
    //             enqueue(temp[1]->right, Q[1]);
    //      }else{
    //          res &= (temp[0] == temp[1]);
    //      }
    //  }

    // return res;



    if(a && b){                     //Solution #2- Go inoder traversal in both tree and check whether same or not.
    
    
        return (identicalTrees(a->left, b->left) && (a->data == b->data) && identicalTrees(a->right, b->right));
    
    }else{                          //if one of them is NULL, both should be NULL.
        return (a == NULL &&  b == NULL);   
    }

}
int main(){
    struct tree *t[2]; struct queue *q[2];

    t[0] = t[1] = NULL;
    q[0] = createQueue(100);
    q[1] = createQueue(100);
    
    int n, i;
    char choice[5];
    do{
        printf("Data to be inserted in 1st tree or 2nd tree?\n");
        scanf("%d",&i);
        printf("Enter the element to be inserted in the %s tree\n", (i == 1) ? "1st" : "2nd");
        scanf("%d",&n);
        insert(&t[i-1], n, q[i-1]);
        printf("Do you want to insert element?\n");
        scanf("%s",choice);
    }while(choice[0]=='y' || choice[0]=='Y');
    
    
    // printf("Inorder 1 "); inorder(t[0]);
    // printf("Inorder 2 "); inorder(t[1]);
    
    if(identicalTrees(t[0], t[1]))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
    return 0;
}
