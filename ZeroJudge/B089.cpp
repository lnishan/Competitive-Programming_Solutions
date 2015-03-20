#include<iostream>
using namespace std;
int m,n,t,w,g;
int main(){
    while(scanf("%d %d",&m,&n) && (m!=0||n!=0))
    {
                    long int pen=0,sol=0,a[m+1][2];
                    for(int i=1;i<=m;i++){a[i][0]=0;a[i][1]=0;}
                    for(int i=0;i<n;i++)
                    {
                            scanf("%d %d %d",&t,&w,&g);
                            if(a[w][0]!=1)
                            {
                                          if(g==1)
                                          {
                                                  a[w][0]=1;
                                                  sol++;
                                                  pen+=(t+20*a[w][1]);
                                          }else{
                                                a[w][1]++;
                                          }
                            }
                    }
                    printf("%d %d\n",pen,sol);
    }
    return 0;
}
