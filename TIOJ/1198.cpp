#include <iostream>

using namespace std;

int st[3][3], mx[4]={1,0,0,-1}, my[4]={0,1,-1,0}, pos[9][2];

int calH(){
    int i, j, c=0;
    for( i=0; i<3; i++)
        for( j=0; j<3; j++ )
            if( st[i][j]>0 ) c+=abs(i-pos[st[i][j]][0])+abs(j-pos[st[i][j]][1]);
    return c;
}

bool DFS_ID(int pi, int g, int limit, int zx, int zy){
    int i, nx, ny, h;
    bool ret;
    h=calH();
    if( g+h>limit ) return false;   // f=g+h
    if( h==0 ) return true;
    for( i=0; i<4; i++ )
    {
        if( i+pi!=3 )
        {
            nx=zx+mx[i]; ny=zy+my[i];
            if( nx>=0 && nx<3 && ny>=0 && ny<3 )
            {
                swap(st[zx][zy], st[nx][ny]);
                ret=DFS_ID(i, g+1, limit, nx, ny);
                swap(st[zx][zy], st[nx][ny]);
                if( ret ) return true;
            }
        }
    }
    return false;
}

int main(){
    int i, j, limit, zx, zy, a;
    bool ret=false;
    for( i=0; i<3; i++ )
        for( j=0; j<3; j++ )
        {
            scanf("%d", &st[i][j]);
            if( st[i][j]==0 )
            {
                zx=i;
                zy=j;
            }
        }
    for( i=0; i<3; i++ )
        for( j=0; j<3; j++ )
        {
            scanf("%d", &a);
            pos[a][0]=i;
            pos[a][1]=j;
        }
    limit=calH();
    do
    {
        ret=DFS_ID(-1, 0, limit, zx, zy);
        limit++;
    }while( ret==false );
    printf("%d", limit-1);
    //while(1);
    return 0;
}