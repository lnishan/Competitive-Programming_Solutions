#include <cstdio>
#include <cstring>

using namespace std;

int x[15], y[15], xpy[30], xmy[40];
char map[15][15];
int n, t[4], ans;

void DFS(int s, int a, int b){
    int i, j;
    if( s==n+1 )
    {
        ans++;
        putchar('\n');
        for( i=0; i<n; i++ )
        {
            for( j=0; j<n; j++ )
                if( map[i][j] )
                    putchar('Q');
                else
                    putchar('x');
            putchar('\n');
        }
    }
    for( i=a; i<n; i++ )
        for( j=(i==a)?b:0; j<n; j++ )
            if( x[i]==0 && y[j]==0 && xpy[i+j]==0 && xmy[i-j+15]==0 )
            {
                x[i]++; y[j]++; xpy[i+j]++; xmy[i-j+15]++;
                map[i][j]=1;
                DFS(s+1, i, j);
                x[i]--; y[j]--; xpy[i+j]--; xmy[i-j+15]--;
                map[i][j]=0;
            }
    return ;
}

int main(){
    int i, j;
    while( scanf("%d", &n)==1 && n>0 )
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(xpy, 0, sizeof(xpy));
        memset(xmy, 0, sizeof(xmy));
        memset(map, 0, sizeof(map));
        ans=0;
        DFS(1, 0, 0);
        putchar('\n');
        printf("%d\n", ans);
    }
    return 0;
}
