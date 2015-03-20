#include <iostream>

using namespace std;

int main(){
    int i, a=1, n;
    scanf("%d", &n);
    for( i=1; i<=n; i++ )
        a*=i;
    printf("%d", a);
    return 0;
}