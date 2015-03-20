#include<iostream>
#include<queue>
using namespace std;
bool a[520][520];
int m,n,ct=0,power[]={0,1,2,4,6,10,12,14,16,18,20};
struct node{
       int x,y;
};
queue<node> q;

void process(int ax,int ay){
    a[ax][ay]=0;
    if(ax-1>=0&&ay-1>=0) if(a[ax-1][ay-1])process(ax-1,ay-1);
    if(ax-1>=0) if(a[ax-1][ay])process(ax-1,ay);
    if(ax-1>=0&&ay+1<n) if(a[ax-1][ay+1])process(ax-1,ay+1);
    if(ay-1>=0) if(a[ax][ay-1])process(ax,ay-1);
    if(ax+1<m && ay-1>=0) if(a[ax+1][ay-1])process(ax+1,ay-1);
    if(ax+1<m) if(a[ax+1][ay])process(ax+1,ay);
    if(ax+1<m && ay+1<n) if(a[ax+1][ay+1])process(ax+1,ay+1);
    if(ay+1<n) if(a[ax][ay+1])process(ax,ay+1);
}
int main(){
    scanf("%d%d",&m,&n);
    char c=getchar();
    for(int i=0;i<m;i++)
    {
            for(int j=0;j<n;j++)
            {
                    c=getchar();
                    a[i][j]=(c-48);
            }
            c=getchar();
    }
    for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                    if(a[i][j])
                    {
                               ct++;
                               process(i,j);
                    }
    int ns=10;
    for(int i=1;i<=10;i++)
            if(power[i]>=ct){ns=i;break;}
    if(ct==0)printf("0"); else printf("%d",ns);
    return 0;
}
