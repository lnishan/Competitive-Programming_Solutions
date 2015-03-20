#include <iostream>

using namespace std;

long long int p(int s){
    long long int r;
    if(s==1)
        return 2;
    else{
        r=p(s/2);
        if(s%2)
            return ((r*r)<<1)%1234567;
        else
            return (r*r)%1234567;
    }
}
int n;
int main(){
    while(scanf("%d",&n)==1)
        if(n==0) puts("0");
        else if(n==1) puts("1");
        else printf("%lld\n",p(n-1));
    return 0;
}
