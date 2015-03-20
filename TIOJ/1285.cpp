#include <iostream>

using namespace std;

long long int ans;
void cal(int a, int b){
    ans+=a/b;
    a%=b;
    if( a==0 )
        return ;
    else
        cal(b, a);
}
int main(){
    int a, b;
    while( scanf("%d%d", &a, &b)==2 )
    {
        ans=0; if( a<b ) swap(a, b);
        cal(a, b);
        printf("%I64d\n", ans);
    }
    return 0;
}