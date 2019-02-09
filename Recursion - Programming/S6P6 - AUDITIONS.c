#include<stdio.h>
#include<math.h>

int bitlength(int n){
    int c=0;
    while(n){
        c++;
        n >>= 1;
    }
    return --c;
}

int findPos(int n){
    return (1<<bitlength(n));    
}
int main(){
    int n;

    scanf("%d",&n);
    printf("%d",findPos(n));

    return 0;
}
