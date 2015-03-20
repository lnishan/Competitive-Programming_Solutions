#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x, y;
} tmp;
queue<node> fq, pq;
int map[10][17], fmap[10][17], pmap[10][17], mx[4]={1,-1,0,0}, my[4]={0,0,1,-1};

int main(){
    int i, j, fx, fy, t, px, py, ex, ey, qx, qy, nx, ny, ct;
map[0][0]=-1;map[0][1]=-1;map[0][2]=-1;map[0][3]=-1;map[0][4]=-1;map[0][5]=-1;map[0][6]=-1;map[0][7]=-1;map[0][8]=-1;map[0][9]=-1;map[0][10]=-1;map[0][11]=-1;map[0][12]=-1;map[0][13]=-1;map[0][14]=-1;map[0][15]=-1;map[0][16]=-1;
map[1][0]=-1;map[1][1]=0;map[1][2]=0;map[1][3]=0;map[1][4]=-1;map[1][5]=0;map[1][6]=0;map[1][7]=0;map[1][8]=0;map[1][9]=0;map[1][10]=0;map[1][11]=0;map[1][12]=-1;map[1][13]=-1;map[1][14]=0;map[1][15]=0;map[1][16]=-1;
map[2][0]=-1;map[2][1]=-1;map[2][2]=0;map[2][3]=0;map[2][4]=-1;map[2][5]=0;map[2][6]=0;map[2][7]=0;map[2][8]=0;map[2][9]=-1;map[2][10]=0;map[2][11]=-1;map[2][12]=0;map[2][13]=-1;map[2][14]=0;map[2][15]=0;map[2][16]=-1;
map[3][0]=-1;map[3][1]=0;map[3][2]=0;map[3][3]=0;map[3][4]=0;map[3][5]=0;map[3][6]=0;map[3][7]=-1;map[3][8]=0;map[3][9]=-1;map[3][10]=-1;map[3][11]=0;map[3][12]=-1;map[3][13]=-1;map[3][14]=0;map[3][15]=-1;map[3][16]=-1;
map[4][0]=-1;map[4][1]=0;map[4][2]=0;map[4][3]=-1;map[4][4]=-1;map[4][5]=0;map[4][6]=0;map[4][7]=0;map[4][8]=-1;map[4][9]=-1;map[4][10]=0;map[4][11]=0;map[4][12]=-1;map[4][13]=-1;map[4][14]=0;map[4][15]=-1;map[4][16]=-1;
map[5][0]=-1;map[5][1]=-1;map[5][2]=0;map[5][3]=0;map[5][4]=0;map[5][5]=0;map[5][6]=0;map[5][7]=-1;map[5][8]=-1;map[5][9]=0;map[5][10]=0;map[5][11]=-1;map[5][12]=0;map[5][13]=-1;map[5][14]=0;map[5][15]=0;map[5][16]=-1;
map[6][0]=-1;map[6][1]=0;map[6][2]=0;map[6][3]=0;map[6][4]=0;map[6][5]=-1;map[6][6]=0;map[6][7]=0;map[6][8]=0;map[6][9]=0;map[6][10]=0;map[6][11]=0;map[6][12]=0;map[6][13]=0;map[6][14]=0;map[6][15]=0;map[6][16]=-1;
map[7][0]=-1;map[7][1]=0;map[7][2]=0;map[7][3]=0;map[7][4]=0;map[7][5]=0;map[7][6]=-1;map[7][7]=-1;map[7][8]=-1;map[7][9]=-1;map[7][10]=0;map[7][11]=-1;map[7][12]=0;map[7][13]=0;map[7][14]=0;map[7][15]=-1;map[7][16]=-1;
map[8][0]=-1;map[8][1]=-1;map[8][2]=-1;map[8][3]=-1;map[8][4]=0;map[8][5]=-1;map[8][6]=0;map[8][7]=-1;map[8][8]=0;map[8][9]=0;map[8][10]=0;map[8][11]=0;map[8][12]=0;map[8][13]=0;map[8][14]=0;map[8][15]=0;map[8][16]=-1;
map[9][0]=-1;map[9][1]=-1;map[9][2]=-1;map[9][3]=-1;map[9][4]=-1;map[9][5]=-1;map[9][6]=-1;map[9][7]=-1;map[9][8]=-1;map[9][9]=-1;map[9][10]=-1;map[9][11]=-1;map[9][12]=-1;map[9][13]=-1;map[9][14]=-1;map[9][15]=-1;map[9][16]=-1;
    memset(fmap, 0, sizeof(fmap));
    memset(pmap, 0, sizeof(pmap));
    scanf("%d%d", &fx, &fy);
    scanf("%d", &t);
    scanf("%d%d%d%d", &px, &py, &ex, &ey);
    fmap[fx][fy]=1; map[fx][fy]=-1;
    tmp.x=fx; tmp.y=fy;
    fq.push(tmp);
    while( !fq.empty() )
    {
        qx=fq.front().x; qy=fq.front().y;
        if( fmap[qx][qy]>=t )
            break;
        else
        {
            for( i=0; i<4; i++ )
            {
                nx=qx+mx[i]; ny=qy+my[i];
                if( map[nx][ny]==0 && !(nx==ex && ny==ey) && fmap[nx][ny]==0 )
                {
                    map[nx][ny]=-1;
                    fmap[nx][ny]=fmap[qx][qy]+1;
                    tmp.x=nx; tmp.y=ny;
                    fq.push(tmp);
                }
            }
            fq.pop();
        }
    }
    if( fmap[px][py]>0 )
        printf("Help!");
    else
    {
        ct=t;
        pmap[px][py]=t;
        tmp.x=px; tmp.y=py;
        pq.push(tmp);
        while( !pq.empty() )
        {
            ct++;
            while( !fq.empty() )
            {
                qx=fq.front().x; qy=fq.front().y;
                if( fmap[qx][qy]>=ct )
                    break;
                else
                {
                    for( i=0; i<4; i++ )
                    {
                        nx=qx+mx[i]; ny=qy+my[i];
                        if( map[nx][ny]==0 && !(nx==ex && ny==ey) && fmap[nx][ny]==0 )
                        {
                            map[nx][ny]=-1;
                            fmap[nx][ny]=fmap[qx][qy]+1;
                            tmp.x=nx; tmp.y=ny;
                            fq.push(tmp);
                        }
                    }
                    fq.pop();
                }
            }
            while( !pq.empty() )
            {
                qx=pq.front().x; qy=pq.front().y;
                if( pmap[ex][ey]>0 ) break;
                if( pmap[qx][qy]>=ct )
                    break;
                else
                {
                    for( i=0; i<4; i++ )
                    {
                        nx=qx+mx[i]; ny=qy+my[i];
                        if( map[nx][ny]==0 && pmap[nx][ny]==0 )
                        {
                            pmap[nx][ny]=pmap[qx][qy]+1;
                            tmp.x=nx; tmp.y=ny;
                            pq.push(tmp);
                        }
                    }
                }
                pq.pop();
            }
            if( pmap[ex][ey]>0 ) break;
        }
        if( pmap[ex][ey]==0 )
            printf("Help!");
        else
            printf("%d", pmap[ex][ey]-t);
    }
    //while(1);
    return 0;
}