#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main(){
    long long int p,q,r;
    while(scanf("%lld%lld%lld",&p,&q,&r)!=EOF)cout<<fixed<<setprecision(0)<<sqrt((p+q+r)*(p+q+r)-4*p*r)<<endl;
    return 0;
}
