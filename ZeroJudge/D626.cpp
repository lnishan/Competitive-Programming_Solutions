#include<iostream>
#include<queue>
using namespace std;
struct node{
       int x,y;
};
node tnode;
queue<node> q;
int n,fx,fy,qx,qy,a[100][100],tx[4]={1,-1,0,0},ty[4]={0,0,1,-1};
int main(){
    scanf("%d",&n);
    char c=getchar();
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
                    a[i][j]=getchar();
            c=getchar();
    }
    scanf("%d%d",&fx,&fy);
    a[fx][fy]='+';
    tnode.x=fx;tnode.y=fy;
    q.push(tnode);
    while(!q.empty())
    {
         for(int i=0;i<4;i++)
         {
                 tnode.x=q.front().x+tx[i];tnode.y=q.front().y+ty[i];
                 if(tnode.x>=0&&tnode.x<n && tnode.y>=0&&tnode.y<n)
                      if(a[tnode.x][tnode.y]=='-')
                      {
                           a[tnode.x][tnode.y]='+';
                           q.push(tnode);
                      }
         }
         q.pop();
    }
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)putchar(a[i][j]);
            putchar('\n');
    }
    return 0;
}
