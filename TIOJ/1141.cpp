#include <iostream>

using namespace std;

int a[10000];
int main(){
    int i, n, c=0, ans=0;
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);
    sort(a, a+n);
    for( i=0; i<n; i++ )
    {
        ans+=(a[i]-c)*(a[i]-c);
        c=a[i];
    }
    printf("%d", ans);
    //while(1);
    return 0;
}