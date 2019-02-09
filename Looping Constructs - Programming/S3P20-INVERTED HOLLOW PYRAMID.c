#include<stdio.h>
#include<string.h>

int main(){
    int n,i,s;
    scanf("%d",&n);
    
    char a[] ="*****************************************************************";
    char b[] ="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    char ii[] ="iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";

    printf("%s\n", (a + (sizeof(char) * (65 - n * 2 + 1))));
    
    for(i = 1,s = 2 * n - 1 - 4; i < n; i++,s -= 2){
        printf("%s%s%s%s%s\n", b + sizeof(char) * (65 - i), "*", ii + sizeof(char) * (65 - s), (i!=(n-1))? "*": "",b + sizeof(char) * (65 - i));
    }
    return 0;
}
