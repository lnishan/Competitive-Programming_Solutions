#include <iostream>

using namespace std;

int main(){
    int h, m;
    while( scanf("%d%d", &h, &m)==2 )
        printf("%d\n", h*60+m);
    return 0;
}
