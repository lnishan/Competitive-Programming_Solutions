#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100][100];

int main(){
    int i, j, t, n, m, flag, x, y;
    scanf("%d", &t);
    while( t-- )
    {
        flag=0;
        x=y=0;
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &m);
        a[0][0]=1;
        if( m==2 )
        {
            for( i=2; i<=n*n; i++ )
            {
                if( flag==0 )
                {
                    x++;
                    if( x+1>=n || a[x+1][y]>0 )
                        flag=1;
                }
                else if( flag==1 )
                {
                    y++;
                    if( y+1>=n || a[x][y+1]>0 )
                        flag=2;
                }
                else if( flag==2 )
                {
                    x--;
                    if( x-1<0 || a[x-1][y]>0 )
                        flag=3;
                }
                else if( flag==3 )
                {
                    y--;
                    if( y-1<0 || a[x][y-1]>0 )
                        flag=0;
                }
                a[x][y]=i;
            }
        }
        else if( m==1 )
        {
            for( i=2; i<=n*n; i++ )
            {
                if( flag==0 )
                {
                    y++;
                    if( y+1>=n || a[x][y+1]>0 )
                        flag=1;
                }
                else if( flag==1 )
                {
                    x++;
                    if( x+1>=n || a[x+1][y]>0 )
                        flag=2;
                }
                else if( flag==2 )
                {
                    y--;
                    if( y-1<0 || a[x][y-1]>0 )
                        flag=3;
                }
                else if( flag==3 )
                {
                    x--;
                    if( x-1<0 || a[x-1][y]>0 )
                        flag=0;
                }
                a[x][y]=i;
            }
        }
        for( i=0; i<n; i++ )
        {
            for( j=0; j<n; j++ )
                printf("%5d", a[i][j]);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
