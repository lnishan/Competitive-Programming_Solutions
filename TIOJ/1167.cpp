#include <iostream>

using namespace std;

int a[1000000];
bool cmp(int a, int b){ return a>b; }
int main(){
    int i, n, k;
    while( scanf("%d%d", &n, &k)==2 && !(n==0 && k==0) )
    {
        for( i=0; i<n; i++ )    
            scanf("%d", &a[i]);
        sort(a, a+n, cmp);
        printf("%d\n", a[k-1]);
    }
    return 0;
}