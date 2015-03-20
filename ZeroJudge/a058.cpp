#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int a[3], k, n;
    a[0]=a[1]=a[2]=0;
    scanf("%d", &k);
    while( k-- )
    {
        scanf("%d", &n);
        a[n%3]++;
    }
    printf("%d %d %d", a[0], a[1], a[2]);
    return 0;
}
