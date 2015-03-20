#include <cstdio>

using namespace std;

int main(){
    int a, b, c, d, s1, s2;
    while( scanf("%d%d%d%d", &a, &b, &c, &d)==4 )
    {
        s1=a*60+b;
        s2=c*60+d;
        s2-=s1;
        printf("%dh %dm\n", s2/60, s2%60);
    }
    return 0;
}
