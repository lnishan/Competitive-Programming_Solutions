#include <iostream>

using namespace std;

int n, m, map[20][20], mx[4]={-1,1,0,0}, my[4]={0,0,-1,1};
char so[4]={'U','D','L','R'}, s[21];
bool found;

void DFS(int x, int y){
    int i, nx, ny;
    for( i=0; i<4; i++ )
    {
        nx=x+mx[i]; ny=y+my[i];
        if( (map[nx][ny]==0 || map[nx][ny]=='T') && nx>=0 && nx<n && ny>=0 && ny<m )
        {
            putchar(so[i]);
            if( map[nx][ny]=='T' ){ found=true; return ; }
            map[nx][ny]=1;
            DFS(nx, ny);
            if( found ) return ;
        }
    }
}

int main(){
    int i, j, t, sx, sy;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d%d\n", &n, &m);
        for( i=0; i<n; i++ )
        {
            gets(s);
            for( j=0; j<m; j++ )
                if( s[j]=='#' )
                    map[i][j]=-1;
                else if( s[j]=='.' )
                    map[i][j]=0;
                else if( s[j]=='S' )
                {
                    map[i][j]='1';
                    sx=i; sy=j;
                }
                else if( s[j]=='T' )
                    map[i][j]=s[j];
        }
        found=false;
        DFS(sx, sy);
        putchar('\n');
    }
    return 0;
}