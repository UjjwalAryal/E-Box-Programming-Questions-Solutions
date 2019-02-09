#include<stdio.h>
#include<stdlib.h>

int prevPowerOf2(int n){ 
    int p = 1; 
    if (n && !(n & (n - 1))) 
        return n; 

    while (p < n)  
        p <<= 1; 
      
    return p>>1; 
}


int minimumTiles(int n, int m){
    if(n < m){
        n = n + m;
        m = n - m;
        n = n - m; 
    }
    
    int x = prevPowerOf2(m);
    
    if(x == m && x==n)
        return 1;
        
    if(m <=1 || n<=1 )
        return m*n;
        
    return minimumTiles(n-x,m) + minimumTiles(x,m-x) + 1;
}


int main(){
    
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d",minimumTiles(n,m));
    return 0;
}
