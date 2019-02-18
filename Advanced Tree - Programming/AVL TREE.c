#include<stdio.h>
#include<stdlib.h>
 
// An AVL tree node
struct node{
    int key;
    struct node *left;
    struct node *right;
    int height;
};
 
// A utility function to get maximum of two integers
int max(int a, int b){
    return (a > b)? a : b;
}

int abs(int x){
    return (x > 0) ? x : -x;
}

// A utility function to get height of the tree
int height(struct node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

 
/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct node* newNode(int key)
{
    struct node* node = (struct node*)
                        malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct node *rightRotate(struct node *x){
    struct node* y = x->right;
    x->right = y->left;
    y->left = x;
    
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct node *leftRotate(struct node *x){
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct node *N){
    return (abs(height(N->left) - height(N->right)) > 1);
}
 
void insert(struct node** t, int key){
    if(*t){
        insert( (key < (*t)->key) ? &((*t)->left) : &((*t)->right) ,key);
        
        (*t)->height = 1 + max(height((*t)->left) , height((*t)->right));
        
        if(getBalance((*t))){
            //do LR or/and RR to make tree balance
            if(key < (*t)->key){           //LR
                if(key < (*t)->left->key)
                    (*t) = leftRotate(*t);
                else{
                    (*t)->left = rightRotate((*t)->left);
                    (*t) = leftRotate(*t);
                }
            }else{                          //RR
                if(key < (*t)->right->key){
                    (*t)->right = leftRotate((*t)->right);
                    (*t) = rightRotate(*t);
                }else{
                    (*t) = rightRotate((*t));
                }
            }
        }
        return;
    }
    *t = newNode(key);
}
 
/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
   
struct node * minValueNode(struct node* node){
       while(node->left)
          node = node->left;
       return node;
}
 
struct node* deleteNodeU(struct node* t, int key){
    
    if(!t){
        printf("Element not found\n");
        return NULL;
    }
    if(key == t->key){
        
        if(!t->left && !t->right){
            return NULL;
        }else if(!t->left && t->right){
            t = t->right;
        }else if(t->left && !t->right){
            t = t->left;
        }else{
            struct node *temp = minValueNode(t->right);
            t->key = temp->key;
            t->right = deleteNodeU(t->right, temp->key);
        }
        
    }else if(key < t->key){
        t->left = deleteNodeU(t->left, key);
    }else{
        t->right = deleteNodeU(t->right, key);
    }
    
    t->height = 1 + max(height(t->left), height(t->right));
        ////////////////////////////////////////////ONLY DELETE FUNCTION TO BE EDITED, OTHER IS FINE....
    if(getBalance((t))){
            //do LR or/and RR to make tree balance
            if(key > (t)->key){           
                if(getBalance(t->right) && key < (t)->right->key){          //RL
                    (t)->right = rightRotate((t)->right);
                    (t) = leftRotate(t);
                }
                else{                           //RR
                    (t) = leftRotate((t));
                }
            }else{                          //LL
                if(getBalance(t->left) && key < (t)->left->key){
                    (t) = rightRotate((t));
                }else{                                  //LR
                    (t)->left = leftRotate((t)->left);
                    (t) = rightRotate((t));
                }
            }
        }
    
    return t;
}
 
 
void deleteNode(struct node **root, int key){
    *root = deleteNodeU(*root, key);
}


// A utility function to print preorder traversal of the tree.
// The function also prints height of every node
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
/* Drier program to test above function*/
int main()
{
	struct node *root = NULL;
	int choice, num;
	/* Constructing tree given in the above figure */
	root = NULL;
	while(1){
		printf("1.Insert the element\n");
		printf("2.Delete the element\n");
		printf("3.Pre-Order traversal\n");
		printf("4.Quit\n");
		printf("Enter your choice :\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to be inserted:\n");
				scanf("%d", &num);
				insert(&root, num);
				break;
			case 2:
				printf("Enter the element to be deleted:\n");
				scanf("%d", &num);
				deleteNode(&root, num);
				break;
			case 3:
				preOrder(root);
				printf("\n");
				break;
			case 4:
				return 0;
			default:
				printf("Invalid choice\n");
		}/*End  of switch */
	}/*End of while */
	return 0;
}/*End of main()*/
