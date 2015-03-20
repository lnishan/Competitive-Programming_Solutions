#include <iostream>

using namespace std;

int main(){
    int n;
    while( scanf("%d", &n)==1 )
    {
        while( n%2==0 ) n/=2;
        printf("%d\n", n);
    }
    return 0;
}
