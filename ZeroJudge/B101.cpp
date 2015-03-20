#include<iostream>
using namespace std;
int main(){
    int n,a[42],c,tn;
    while(scanf("%d",&n)&&n!=0)
    {
                               for(int i=1;i<=41;i++)a[i]=0;
                               for(int i=0;i<n;i++)
                               {
                                       scanf("%d",&c);
                                       for(int j=0;j<c;j++){scanf("%d",&tn);a[tn]++;}
                               }
                               int m=50000;
                               for(int i=1;i<=41;i++)m=min(m,a[i]);
                               printf("%d\n",m);
    }
    return 0;
}
