#include<iostream>

using namespace std;

int a[10001],two,n,ct=0;

int main(){
    a[0]=-1; two=1;
    for(int i=0;i<14;i++)
    {
        a[two]=a[two/2]+1;
        for(int j=two+1;j<=two*2,j<=10000;j++) a[j]=a[two]+1;
        two*=2;
    }
    while(scanf("%d",&n),n>0)
        printf("Case %d: %d\n",++ct,a[n]);
    return 0;
}
