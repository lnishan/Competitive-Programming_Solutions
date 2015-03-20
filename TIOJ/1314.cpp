#include <iostream>

using namespace std;

int main(){
    int t;
    long long int a[3];
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%I64d%I64d%I64d", &a[0], &a[1], &a[2]);
        if( a[0]>0 && a[1]>0 && a[2]>0 )
        {
            sort(a, a+3);
            puts(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]?"yes":"no");
        }
        else
            puts("no");
    }
    return 0;
}