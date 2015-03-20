// 860 1000
#include <iostream>

using namespace std;

int main(){
    int h, m, s;
    while( scanf("%d%d", &h, &m)==2 )
    {
        s=h*60+m;
        if( s>=860 && s<=1000 )
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
