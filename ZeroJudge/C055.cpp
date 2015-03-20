#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a[10001],n,ans;a[0]=1;
    for(int i=1;i<10001;i++)
    {
            a[i]=a[i-1]*i;
            while(a[i]%10==0)a[i]/=10;
            if(a[i]>100000)a[i]%=100000;
    }
    while(scanf("%d",&n)!=EOF){
                               cout<<setw(5)<<right<<n; printf(" -> %d\n",a[n]%10);}
    return 0;
}
