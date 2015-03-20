#include<iostream>
using namespace std;
int cA,cB,cDraw,n;
int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
void DFS(int flag,int x,int y,int anow[4][4],int ac,int bc){
    int avail,tn;
    if(flag)ac+=anow[x][y];else bc+=anow[x][y];
    anow[x][y]=-1;
    if(flag){
             avail=0;
             for(int i=0;i<n;i++)
             {
                     if(anow[i][y]!=-1){
                          avail++;
                          tn=anow[i][y];
                          DFS(0,i,y,anow,ac,bc);
                          anow[i][y]=tn;
                     }
             }
    }else{
          avail=0;
          for(int i=0;i<n;i++)
          {
                  if(anow[x][i]!=-1){
                       avail++;
                       tn=anow[x][i];
                       DFS(1,x,i,anow,ac,bc);
                       anow[x][i]=tn;
                  }
          }
    }
    if(avail==0){
                 if(ac>bc)cA++;
                 else if(ac<bc)cB++;
                 else cDraw++;
    }
}
int main(){
    int a[4][4],tn;
    while(scanf("%d",&n)==1)
    {
         cA=cB=cDraw=0;
         for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                         a[i][j]=input();
         for(int i=0;i<n;i++)
         {
                 tn=a[0][i];
                 DFS(1,0,i,a,0,0);
                 a[0][i]=tn;
         }
         printf("%d %d %d\n",cA,cB,cDraw);
    }
    return 0;
}
