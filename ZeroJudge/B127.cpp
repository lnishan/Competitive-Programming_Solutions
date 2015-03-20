#include<iostream>
using namespace std;
int main(){
    long long int n[46];n[0]=n[1]=1;int no;
    for(int i=2;i<=45;i++)n[i]=n[i-1]+n[i-2];
    while(scanf("%d",&no)!=EOF)printf("%lld\n",n[no]);
    return 0;
}
