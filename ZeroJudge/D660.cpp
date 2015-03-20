#include<iostream>

using namespace std;

int t,ns,pn,n,high,low;

int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        high=low=0;
        scanf("%d%d",&ns,&pn);
        for(int j=1;j<ns;j++)
        {
            scanf("%d",&n);
            if(n>pn) high++;
            else if(n<pn) low++;
            pn=n;
        }
        printf("Case %d: %d %d\n",i,high,low);
    }
    return 0;
}
            
