#include <iostream>

using namespace std;

int main(){
    int h, m;
    while( scanf("%d", &m)==1 )
        printf("%d %d\n", m/60, m%60);
    return 0;
}
