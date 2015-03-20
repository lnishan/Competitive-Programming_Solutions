#include <iostream>

using namespace std;

int main(){
    int i, n, ans;
    while( scanf("%d", &n)==1 )
    {
        ans=0;
        while( n>=5 )
        {
            ans+=(n/5)*5;
            n-=(n/5)*4;
        }
        ans+=n;
        printf("%d\n", ans);
    }
    return 0;
}
