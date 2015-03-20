#include<iostream>
using namespace std;
int main(){
    long long int n;
    while(scanf("%lld",&n)!=EOF) printf("%lld\n",((n+3)*(n-1)/2-1)*3);
    return 0;
}
