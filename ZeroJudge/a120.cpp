#include <cstdio>

using namespace std;

int main(){
    unsigned int n;
    int c;
    while( scanf("%u", &n)==1 )
    {
        c=0;
        while( n>0 )
        {
            c+=n%10;
            n/=10;
        }
        printf("%d\n", c);
    }
    return 0;
}
