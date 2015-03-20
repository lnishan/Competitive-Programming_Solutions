#include <iostream>
#include <queue>

using namespace std;

struct node{ int x, y; } no, qi;
char a[1000][1000];
queue<node> q;
char s[1002];

int main(){
    int i, j, k, m, n, sc, nx, ny, mx[8]={1,1,1,-1,-1,-1,0,0}, my[8]={1,0,-1,1,0,-1,1,-1};
    while( scanf("%d%d", &m, &n) && (m!=0||n!=0) )
    {
        scanf("\n");
        sc=0;
        for( i=0; i<m; i++ )
        {
            gets(s);
            for( j=0; j<n; j++ )
                a[i][j]=s[j]-48;
        }
        for( i=0; i<m; i++ )
            for( j=0; j<n; j++ )
                if( a[i][j]==1 )
                {
                    no.x=i; no.y=j;
                    a[i][j]=0;
                    q.push(no);
                    while( !q.empty() )
                    {
                        qi=q.front();
                        for( k=0; k<8; k++ )
                        {
                            nx=qi.x+mx[k];
                            ny=qi.y+my[k];
                            if( nx>=0 && nx<m && ny>=0 && ny<n )
                                if( a[nx][ny]==1 )
                                {
                                    a[nx][ny]=0;
                                    no.x=nx; no.y=ny;
                                    q.push(no);
                                }
                        }
                        q.pop();
                    }
                    sc++;
                }
        printf("%d\n", sc);
    }    
    return 0;
}