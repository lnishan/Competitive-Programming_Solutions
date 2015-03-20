#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
    char n;
    long long int p;
} a[3];

bool cmp(node a, node b){
    return a.p<b.p;
}

int main(){
    int i, l, m;
    while( scanf("%lld%lld%lld", &a[0].p, &a[1].p, &a[2].p)==3 )
    {
        a[0].n='A'; a[1].n='B'; a[2].n='C';
        sort(a, a+3, cmp);
        a[1].p+=a[0].p;
        a[0].p=0;
        sort(a, a+3, cmp);
        putchar(a[2].n);
        putchar('\n');
    }
    return 0;
}
