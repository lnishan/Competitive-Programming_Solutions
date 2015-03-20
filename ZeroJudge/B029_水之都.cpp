#include<iostream>
#include<queue>
using namespace std;
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int w[1001][1001],n,m,r_st,r_ed,qi,tw;
queue<int> q;
int main(){
    freopen("pd.in","r",stdin);
    freopen("pd.out","w",stdout);
    while(n=input(),m=input(),n!=0||m!=0)
    {
         for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=0;
         for(int i=0;i<m;i++)
         {
                 r_st=input();
                 r_ed=input();
                 tw=input();
                 w[r_st][r_ed]=max(w[r_st][r_ed],tw);
                 w[r_ed][r_st]=w[r_st][r_ed];
         }
         r_st=input(); r_ed=input();
         for(int j=1;j<=n;j++)
                 if(w[r_st][j]!=0)q.push(j);
         while(!q.empty())
         {
              qi=q.front();
              for(int j=1;j<=n;j++)
              {
                      tw=min(w[r_st][qi],w[qi][j]);
                      if(tw>w[r_st][j]){
                           w[r_st][j]=tw;
                           q.push(j);
                      }
              }
              q.pop();
         }
         printf("%d\n",w[r_st][r_ed]);
    }
    return 0;
}
