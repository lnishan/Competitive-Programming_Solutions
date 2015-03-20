#include<iostream>
using namespace std;
int a[10001],n;
int main(){
    a[0]=1;a[1]=1;
    for(int i=2;i<=10000;i++) a[i]=(a[i-1]+a[i-2])%2012;
    while(cin>>n) cout<<a[n]<<endl;
    return 0;
}
