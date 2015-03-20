#include<iostream>
using namespace std;
int main(){
    long long int a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)printf("%lld\n",(a*(a+1)/2)*(b*(b+1)/2));
    return 0;
}
