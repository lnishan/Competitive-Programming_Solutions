#include<iostream>
#include<queue>

using namespace std;

int ds,ns,rs,rst,red,w[101][101],tw,qi;
queue<int> q;

int input(){
    char c;
    while((c=getchar())==' '||c=='\n');
    int x=c-48;
    while((c=getchar())!=' '&&c!='\n')x=x*10+c-48;
    return x;
}
int main(){
    ds=input();
    for(int d=0;d<ds;d++)
    {
            ns=input();
            rs=input();
            for(int i=1;i<=ns;i++) for(int j=1;j<=ns;j++) w[i][j]=0;
            for(int i=0;i<rs;i++)
            {
                    rst=input();
                    red=input();
                    w[rst][red]=input();
                    w[red][rst]=w[rst][red];
            }
            rst=1; red=ns;
            for(int i=1;i<=ns;i++)
                    if(w[rst][i]!=0) q.push(i);
            while(!q.empty())
            {
                 qi=q.front();
                 for(int i=1;i<=ns;i++)
                 {
                         tw=max(w[rst][qi],w[qi][i]);
                         if(w[rst][qi]!=0 && w[qi][i]!=0 && tw!=0 && (tw<w[rst][i]||w[rst][i]==0)){
                              w[rst][i]=tw;
                              q.push(i);
                         }
                 }
                 q.pop();
            }
            printf("%d\n",w[1][red]);
    }
    return 0;
}
                              
