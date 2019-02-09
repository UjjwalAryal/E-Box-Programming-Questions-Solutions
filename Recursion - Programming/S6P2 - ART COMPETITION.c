#include<stdio.h>


void printnumbers(int x){
    if(x==0) return;
    
    printnumbers(x-1);
    
    printf("%d ",x);
    
}

int main(){
    int n;
    scanf("%d",&n);
    printnumbers(n);
    return 0;
}
