#include<stdio.h>
#include<stdlib.h>
struct term
{
    int coeff ;
    int expo;
    struct term * next;
} ;

void polyappend ( struct term **poly, int coeff, int expo ){
   struct term * x= (struct term *) malloc(sizeof (struct term));
  struct term *temp=*poly;
  x->coeff=coeff;
  x->expo=expo;
  x->next= NULL;
  if(*poly== NULL){
   *poly=x;
  }
  else{
    while(temp->next!=NULL) {
      temp=temp->next;
    }
    temp->next=x;
  }
}
struct term * polyadd(struct term *poly1, struct term *poly2){
    int i;
    int max_ = (poly1->expo > poly2->expo) ? poly1->expo : poly2->expo ;
    int res[max_+1];
    
    for(i = 0; i <= max_; i++)  res [i] = 0;
    i = 0;
    
    while(poly1){
        res[poly1->expo] += poly1->coeff;
        poly1 = poly1->next;
    }
    
    while(poly2){
        res[poly2->expo] += poly2->coeff;
        poly2 = poly2->next;
    }
    struct term *nn, *new = NULL;
    while(i <= max_){
        nn = (struct term*)malloc(sizeof(struct term));
        nn->coeff = res[i];
        nn->expo = i;
        if(nn->coeff){    
            nn->next = new;
            new = nn;
        }
        i++;
    }
    return new;
}

void display(struct term *poly){
  while(poly->next!=NULL){
    printf("%d ",poly->coeff);
    if(poly->expo!=0){
      printf("x^%d ",poly->expo);
    }
    if(poly->next->coeff>=0){
      printf("+ ");
    }
    poly = poly->next;
  }
  if(poly!=NULL){
    if(poly->coeff>=0){
      printf("%d",poly->coeff);
      if(poly->expo!=0){
        printf(" x^%d",poly->expo);
      }
    }
  }
  printf("\n");
}
int main(){
  int m,n,i,coeff,expo;
  struct term * poly1 = NULL;
  struct term * poly2= NULL;
  struct term * polySum;
  printf("Enter the number of terms in the first polynomial\n");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter the coefficient and exponent of term %d in the first polynomial:\n",i+1);
    scanf("%d%d",&coeff,&expo);
    polyappend(&poly1,coeff,expo);
  }
  printf("Enter the number of terms in the second polynomial\n");
  scanf("%d",&m);
  for(i=0;i<m;i++){
    printf("Enter the coefficient and exponent of term %d in the second polynomial:\n",i+1);
    scanf("%d%d",&coeff,&expo);
    polyappend(&poly2,coeff,expo);
  }
  printf("First Polynomial:\n");
  display(poly1);
  printf("Second Polynomial:\n");
  display(poly2);
  polySum = polyadd(poly1,poly2);
  printf("Resultant Polynomial:\n");
  display(polySum);
  return 0;
}
