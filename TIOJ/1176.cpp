#include <iostream>

using namespace std;

int stk[1000000][2], ans[1000000];

int main(){
    int i, n, a, top=-1, top2=-1, oc=0;
    scanf("%d%d", &n, &a);
    stk[++top][0]=a;
    stk[  top][1]==0;
    for( i=1; i<n; i++ )
    {
        scanf("%d", &a);
        if( top==-1 )
        {
            stk[++top][0]=a;
            stk[  top][1]=i;
        }
        else
        {
            if( a>=stk[top][0] )
                while( top>=0 && a>=stk[top][0] )
                    ans[stk[top][1]]=i-stk[top--][1];
            stk[++top][0]=a;
            stk[  top][1]=i;
        }
    }
    for( i=top; i>=0; i-- )
        ans[stk[i][1]]=stk[top][1]-stk[i][1];
    for( i=0; i<n; i++ )
        printf("%d\n", ans[i]);
    //while(1);
    return 0;
}
