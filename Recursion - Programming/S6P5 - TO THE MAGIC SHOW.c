#include<stdio.h>

int isReachable(int x1, int y1, int x2, int y2){
    if(x1>x2 || y1>y2) return 0;
    if(x1==x2 && y1==y2)
        return 1;
    
    return isReachable(x1,x1+y1,x2,y2) || isReachable(x1+y1, y1, x2,y2);
}

int main(){
    int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    printf("%s", isReachable(x1,y1,x2,y2) ? "True" : "False" );
    return 0;
}
