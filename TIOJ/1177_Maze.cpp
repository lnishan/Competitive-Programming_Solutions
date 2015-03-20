#include<iostream>
#include<queue>
using namespace std;
int a[1001][1001];
struct cord{
       int x,y;
};
int main(){
    queue<cord> q;
    int m,n,tx,ty;
    cord st,ed,tcd;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
         for(int i=1;i<=m;i++)for(int j=1;j<m;j++)a[i][j]=0;
         for(int i=0;i<n;i++)
                 {scanf("%d%d",&tx,&ty);a[tx][ty]=-1;}
         scanf("%d%d%d%d",&st.x,&st.y,&ed.x,&ed.y);
         q.push(st);
         while(!q.empty())
         {
                          if(q.front().x!=1)
                                        if(a[q.front().x-1][q.front().y]==0)
                                        {
                                             a[q.front().x-1][q.front().y]=a[q.front().x][q.front().y]+1;
                                             tcd.x=q.front().x-1;tcd.y=q.front().y;
                                             q.push(tcd);
                                        }
                          if(q.front().y!=1)
                                        if(a[q.front().x][q.front().y-1]==0)
                                        {
                                             a[q.front().x][q.front().y-1]=a[q.front().x][q.front().y]+1;
                                             tcd.x=q.front().x;tcd.y=q.front().y-1;
                                             q.push(tcd);
                                        }
                          if(q.front().x+1<=m)
                                        if(a[q.front().x+1][q.front().y]==0)
                                        {
                                             a[q.front().x+1][q.front().y]=a[q.front().x][q.front().y]+1;
                                             tcd.x=q.front().x+1;tcd.y=q.front().y;
                                             q.push(tcd);
                                        }
                          if(q.front().y+1<=m)
                                        if(a[q.front().x][q.front().y+1]==0)
                                        {
                                             a[q.front().x][q.front().y+1]=a[q.front().x][q.front().y]+1;
                                             tcd.x=q.front().x;tcd.y=q.front().y+1;
                                             q.push(tcd);
                                        }
                          q.pop();
         }
         if(a[ed.x][ed.y]==0||a[ed.x][ed.y]==-1)printf("-1\n");else printf("%d\n",a[ed.x][ed.y]);
    }
    return 0;
}
