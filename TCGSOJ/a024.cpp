#include <iostream>

using namespace std;

int main(){
    int n, ans;
    while( scanf("%d", &n)==1 )
    {
        ans=0;
        while( n>0 )
        {
            ans+=n%10;
            n/=10;
        }
        printf("%d\n", ans);
    }
    return 0;
}
