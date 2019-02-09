//INCOMPLETE
#include<stdio.h>
#include<stdlib.h>

int a, b;

int min(int x, int y){
    return (x<y) ? x : y;
}

int max(int x, int y){
    return (x>y) ? x: y;
}

int comparator(const void *p, const void *q){
	return (((int *)p) > ((int *)q));
}
int minSteps_(int as, int bs, int c, int count){
    if(as == c || bs == c)
        return count;
    if(count > 50 && as == 0 && bs == 0)
        return -1;
        
    int aa[6], i;
    if(as == 0)
        aa[0] = minSteps_(a , bs, c, count + 1);
    else
        aa[0] = -1;
    if(bs==0)    
        aa[1] = minSteps_(as, b, c, count + 1);
    else
        aa[1] = -1;
    aa[2] = minSteps_(as + min(a-as,bs), bs - min(a-as, bs), c, count + 1);
    aa[3] = minSteps_(as - min(b-bs,as), bs + min(b-bs, as), c, count + 1);
    aa[4] = minSteps_(0, bs, c, count + 1);
    aa[5] = minSteps_(as, 0, c, count + 1);
    
    qsort(aa,6,sizeof(int),comparator);
    
    int min_ = 999999;
    
    for(i=0; i<5; i++){
	    if(aa[i] != -1)
		    min_ = min(min_, aa[i]);
    }
	return (min_ == 999999) ? -1 : min_;
}
int minSteps(int x, int y, int c){
    a = x;
    b = y;
    return minSteps_(0,0, c, 0);
}

int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",minSteps(a,b,c));
    return 0;
}
