#include <iostream>

using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%d", &n);
        printf("%d\n", n%2);
    }
    return 0;
}