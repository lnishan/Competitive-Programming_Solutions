#include<iostream>
using namespace std;
int main(){
    long long int n,m;
    while(scanf("%lld%lld",&n,&m) && (n!=0||m!=0)){
                     long long int ans=n;
                     if(m>n/2)m=n-m;
                     if(m==0)
                             ans=1;
                     else
                          for(int i=1;i<m;i++)
                                  ans=ans*(n-i)/(i+1);
                     printf("%lld\n",ans);
    }
    return 0;
}
