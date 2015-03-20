#include <cstdio>

using namespace std;

int main(){
    int n, m;
    while( scanf("%d%d", &n, &m)==2 )
        printf("%d\n", m+(n!=m));
    return 0;
}
