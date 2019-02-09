#include<stdio.h>
#include<math.h>

#define LENGTH(x) ((int)(log10((double)x)))

int reverse(int x){
    if(x<10) return x;
    return ((x%10) * pow(10,LENGTH(x)) + reverse(x/10));
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",reverse(n));
    return 0;
}
