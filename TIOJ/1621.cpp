#include <stdio.h>

int stk[250000];

int main(){
    int i, n, t, h, top=-1, c=0;
    scanf("%d", &n);
    scanf("%d %d", &t, &h);
    stk[++top]=h;
    for(i=1; i<n; i++)
    {
        scanf("%d %d", &t, &h);
        while( top>=0 && h<stk[top] )
            --top;
        if( top>=0 )
            if( stk[top]==h ){
                c++;
                --top;
            }
        stk[++top]=h;
    }
    printf("%d", n-c);
    //while(1);
    return 0;
}