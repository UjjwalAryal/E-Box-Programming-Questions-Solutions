#include<stdio.h>
#include<string.h>

/*Python program ****need to be translated***
def printu(x,ones,zeros,current):
    if(len(current) == x):
        print(current)
        return
    printu(x, ones+1, zeros, current + '1')
    
    if(ones  > zeros):
        printu(x, ones, zeros+1, current + '0')
        
printu(2,0,0,'')

*/



void print(int x, int ones, int zeros, char current[1000]){
    
    if(strlen(current) == x){
        printf("%s ",current);
        return;
    }
    
    char temp[1000];
    strcpy(temp, current);
    strcat(temp,"1");
    
    int len = strlen(temp);
    
    print(x, ones + 1, zeros, temp);
    
    temp[len-1] = '0';
    
    if(ones > zeros)
        print(x, ones, zeros + 1, temp);
    return;
}

void printNums(int x){
    char s[1000] = "";
    print(x, 0, 0, s);
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    printNums(n);
    return 0;
}
