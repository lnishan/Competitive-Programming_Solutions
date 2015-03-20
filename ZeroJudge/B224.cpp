#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node{
       int x,y;
};
int a[100][100];
int main(){
    int row,col,ans;
    string s;
    node k,t;
    while(scanf("%d",&row)&&row!=0)
    {
         char c=getchar();
         getline(cin,s);
         col=s.length();
         for(int i=0;i<col;i++)
                 if(s[i]=='#') a[0][i]=-1;
                 else if(s[i]=='.') a[0][i]=0;
                 else if(s[i]=='@') a[0][i]=-2;
         for(int i=1;i<row;i++)
         {
                 for(int j=0;j<col;j++)
                 {
                         c=getchar();
                         if(c=='#') a[i][j]=-1;
                         else if(c=='.') a[i][j]=0;
                         else if(c=='@') a[i][j]=-2;
                         else if(c=='K'){a[i][j]=0;k.x=i;k.y=j;}
                 }
                 c=getchar();
         }
         queue<node> q;
         q.push(k);
         ans=-1;
         while(!q.empty())
         {
                          if(a[q.front().x+1][q.front().y]==-2 || a[q.front().x-1][q.front().y]==-2 || a[q.front().x][q.front().y+1]==-2 || a[q.front().x][q.front().y-1]==-2){ans=a[q.front().x][q.front().y]+1;break;}
                          if(a[q.front().x+1][q.front().y]==0){
                               a[q.front().x+1][q.front().y]=a[q.front().x][q.front().y]+1;
                               t.x=q.front().x+1;t.y=q.front().y;
                               q.push(t);
                          }
                          if(a[q.front().x-1][q.front().y]==0){
                               a[q.front().x-1][q.front().y]=a[q.front().x][q.front().y]+1;
                               t.x=q.front().x-1;t.y=q.front().y;
                               q.push(t);
                          }
                          if(a[q.front().x][q.front().y+1]==0){
                               a[q.front().x][q.front().y+1]=a[q.front().x][q.front().y]+1;
                               t.x=q.front().x;t.y=q.front().y+1;
                               q.push(t);
                          }
                          if(a[q.front().x][q.front().y-1]==0){
                               a[q.front().x][q.front().y-1]=a[q.front().x][q.front().y]+1;
                               t.x=q.front().x;t.y=q.front().y-1;
                               q.push(t);
                          }
                          q.pop();
         }
         if(ans==-1)printf("= =\"\n");else printf("%d\n",ans);
    }
    return 0;
}
