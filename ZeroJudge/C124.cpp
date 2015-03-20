#include<iostream>
#include<queue>

using namespace std;

struct cord{
       int x,y,z;
};

int l,r,c,stx,sty,stz,edx,edy,edz,qx,qy,qz,nx,ny,nz,stps,a[30][30][30],tx[6]={1,-1,0,0,0,0},ty[6]={0,0,1,-1,0,0},tz[6]={0,0,0,0,1,-1};
char tch[31];
queue<cord> q;
cord tcd;

int main(){
    while(scanf("%d%d%d",&l,&r,&c) && (l!=0||r!=0||c!=0))
    {
         memset(a,0,sizeof(a));
         stps=-1;
         gets(tch);
         for(int i=0;i<l;i++)
         {
                 for(int j=0;j<r;j++)
                 {
                         gets(tch);
                         for(int k=0;k<c;k++)
                                 if(tch[k]=='#')a[i][j][k]=-1;
                                 else if(tch[k]=='S'){stx=i;sty=j;stz=k;}
                                 else if(tch[k]=='E'){edx=i;edy=j;edz=k;}
                 }
                 gets(tch);
         }
         tcd.x=stx;tcd.y=sty;tcd.z=stz;
         q.push(tcd);
         while(!q.empty())
         {
               qx=q.front().x;qy=q.front().y;qz=q.front().z;
               for(int i=0;i<6;i++)
               {
                       nx=qx+tx[i];ny=qy+ty[i];nz=qz+tz[i];
                       if(nx==edx&&ny==edy&&nz==edz)
                       {
                            stps=a[qx][qy][qz]+1;
                            while(!q.empty())q.pop();
                            break;
                       }
                       if(nx<l&&nx>=0 && ny<r&&ny>=0 && nz<c&&nz>=0 && a[nx][ny][nz]==0)
                       {
                            a[nx][ny][nz]=a[qx][qy][qz]+1;
                            tcd.x=nx;tcd.y=ny;tcd.z=nz;
                            q.push(tcd);
                       }
               }
               if(q.empty())break;
               q.pop();
         }
         if(stps==-1)printf("Trapped!\n");else printf("Escaped in %d minute(s).\n",stps);
    }
    return 0;
}
