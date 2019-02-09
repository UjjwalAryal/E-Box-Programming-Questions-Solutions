#include<stdio.h>

int summation(int n,int m){
    if(m > 1)
        return summation(summation(n,m-1),1);
    return (n*(n+1)*0.5);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",summation(n,m));
    return 0;
}
