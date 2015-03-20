#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

int n, a[10000];

void dfs(int r, int c){
    int i, p=c==0?n:a[c-1];
    if( r==0 )
    {
        for( i=0; i<c; i++ )
        {
			if( i>0 ) putchar(' ');
            printf("%d", a[i]);
		}
        putchar('\n');
        return ;
    }
    for( i=min(r,p); i>=1; i-- )
    {
        a[c]=i;
        dfs(r-i, c+1);
    }
    return ;
}

int main(){
    int t=0;
    while( scanf("%d", &n)==1 )
    {
        printf("case %d:\n", ++t);
        dfs(n, 0);
        putchar('\n');
    }
    return 0;
}
