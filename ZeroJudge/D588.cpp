#include<iostream>
using namespace std;
int main(){
    int ds,ts,a,b,h1,c,d,h2,hmax;
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            scanf("%d",&ts);
            hmax=0;
            for(int j=0;j<ts;j++)
                    {scanf("%d %d %d %d %d %d",&a,&b,&h1,&c,&d,&h2);hmax=max(hmax,h1);hmax=max(hmax,h2);}
            printf("%d\n",hmax);
    }
    return 0;
}
