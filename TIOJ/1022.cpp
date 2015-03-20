#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x, y;
} tmp;
queue<node> q;

int map[100][100], a[100][100], mx[4]={1,-1,0,0}, my[4]={0,0,1,-1};

int main(){
    int i, j, t, m, n, qx, qy, nx, ny;
    scanf("%d", &t);
    while( t-- )
    {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &m, &n);
        for( i=0; i<m; i++ )
            for( j=0; j<n; j++ )
                scanf("%d", &map[i][j]);
        tmp.x=0; tmp.y=0;
        q.push(tmp);
        while( !q.empty() )
        {
            qx=q.front().x; qy=q.front().y;
            for( i=0; i<4; i++ )
            {
                nx=qx+mx[i]; ny=qy+my[i];
                if( nx>=0 && nx<m && ny>=0 && ny<n && a[nx][ny]==0 && abs(map[qx][qy]-map[nx][ny])<=5 )
                {
                    a[nx][ny]=a[qx][qy]+1;
                    tmp.x=nx; tmp.y=ny;
                    q.push(tmp);
                }
            }
            q.pop();
        }
        printf("%d\n", a[m-1][n-1]);
    }
    return 0;
}