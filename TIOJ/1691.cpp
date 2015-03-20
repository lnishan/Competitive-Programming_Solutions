#include <iostream>

using namespace std;

struct node{
    int n, i;
} a[100000];

bool cmp(node a, node b){
    if( a.n!=b.n )
        return a.n<b.n;
    else
        return a.i<b.i;
}

int main(){
    int i, n, miabs;
    scanf("%d", &n);
    miabs=n;
    for( i=0; i<n; i++ )
    {
        scanf("%d", &a[i].n);
        a[i].i=i;
    }
    sort(a, a+n, cmp);
    for( i=0; i<n-1; i++ )
        if( a[i].n==a[i+1].n )
            miabs=min(miabs, abs(a[i].i-a[i+1].i));
    printf("%d", n-miabs);
    //while(1);
    return 0;
}