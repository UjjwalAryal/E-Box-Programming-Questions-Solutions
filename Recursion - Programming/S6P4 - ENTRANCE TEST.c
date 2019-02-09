#include<stdio.h>
#include<math.h>

int count(int num, int x, int k, int n ){
    static int res = 0;
    if(x == 0)
        res++;
    
    int i, a, r = (int)pow(num, 1.0/(double)n);
    for(i = k + 1; i <= r; i++){
        a = x - (int)pow(i, n);
        if(a >= 0)
            count(num, a, i, n);
    }
    return res;
}

int countWays(int x, int n){
    return count(x,x,0,n);
}
int main(){
    int x, n;
    scanf("%d%d",&x,&n);
    printf("%d",countWays(x,n));
    return 0;
}
