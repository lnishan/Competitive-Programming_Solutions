#include<iostream>
using namespace std;
int main(){
    int t,n,k;
    long int a[100001],m;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
            scanf("%d %d",&n,&k);
            for(int j=0;j<n;j++)scanf("%d",&a[j]);
            for(int j=0;j<k;j++)
            {
                    scanf("%d",&m);
                    for(int k=0;k<n;k++) if(a[k]==m){printf("%d\n",k+1);break;}
            }
    }
    return 0;
}
