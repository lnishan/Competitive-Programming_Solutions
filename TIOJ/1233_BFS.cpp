#include<iostream>
#include<queue>
using namespace std;
bool a[520][520];
int m,n,ct=0,power[]={0,1,2,4,6,10,12,14,16,18,20},ax,ay;
struct node{
       int x,y;
};
queue<node> q;
node tcd;
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
                               tcd.x=i;tcd.y=j;
                               q.push(tcd);
                               while(!q.empty())
                               {
                                                ax=q.front().x;ay=q.front().y;
                                                a[ax][ay]=0;
                                                if(ax-1>=0&&ay-1>=0) if(a[ax-1][ay-1]){tcd.x=ax-1;tcd.y=ay-1;q.push(tcd);};
                                                if(ax-1>=0) if(a[ax-1][ay]){tcd.x=ax-1;tcd.y=ay;q.push(tcd);};
                                                if(ax-1>=0&&ay+1<n) if(a[ax-1][ay+1]){tcd.x=ax-1;tcd.y=ay+1;q.push(tcd);};
                                                if(ay-1>=0) if(a[ax][ay-1]){tcd.x=ax;tcd.y=ay-1;q.push(tcd);};
                                                if(ax+1<m && ay-1>=0) if(a[ax+1][ay-1]){tcd.x=ax+1;tcd.y=ay-1;q.push(tcd);};
                                                if(ax+1<m) if(a[ax+1][ay]){tcd.x=ax+1;tcd.y=ay;q.push(tcd);};
                                                if(ax+1<m && ay+1<n) if(a[ax+1][ay+1]){tcd.x=ax+1;tcd.y=ay+1;q.push(tcd);};
                                                if(ay+1<n) if(a[ax][ay+1]){tcd.x=ax;tcd.y=ay+1;q.push(tcd);};
                                                q.pop();
                               }
                    }
    int ns=10;
    for(int i=1;i<=10;i++)
            if(power[i]>=ct){ns=i;break;}
    if(ct==0)printf("0"); else printf("%d",ns);
    return 0;
}
