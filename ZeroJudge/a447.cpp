#include <cstdio>

using namespace std;

int main(){
    int a, n, c[3];
    while( scanf("%d", &n)==1 )
    {
        c[0]=c[1]=c[2]=0;
        while( n-- )
        {
            scanf("%d", &a);
            c[a%3]++;
        }
        printf("%d %d %d\n", c[0], c[1], c[2]);
    }
    return 0;
}
