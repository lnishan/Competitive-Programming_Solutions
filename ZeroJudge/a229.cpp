#include <cstdio>

using namespace std;

int a[30], n;

void dfs(int l, int r){
    int i;
    if( l>n && r>n )
    {
        for( i=0; i<2*n; i++ )
            if( a[i] )
                putchar('(');
            else
                putchar(')');
        putchar('\n');
        return ;
    }
    if( l<=n )
    {
        a[l+r-2]=1;
        dfs(l+1, r);
    }
    if( l>r )
    {
        a[l+r-2]=0;
        dfs(l, r+1);
    }
    return ;
}

int main(){
    while( scanf("%d", &n)==1 )
    {
        dfs(1, 1);
        putchar('\n');
    }
    return 0;
}
