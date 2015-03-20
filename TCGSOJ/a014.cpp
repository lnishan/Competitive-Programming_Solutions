#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    while( scanf("%d%d%d", &a, &b, &c)==3 )
    {
        a=min(a, b);
        a=min(a, c);
        printf("%d\n", a);
    }
    return 0;
}
