#include <iostream>

using namespace std;

int n, a[100000], t[100000];
long long int ans;

void merge(int l, int r){
    int i, i1, i2, m;
    if( l>=r ) return ;
    m=(l+r)/2;
    merge(l, m);
    merge(m+1, r);
    for( i=l,i1=l,i2=m+1; ; i++ )
    {
        if( i1<=m && i2<=r )
        {
            if( a[i1]>a[i2] )
                t[i]=a[i2++];
            else
            {
                t[i]=a[i1++];
                ans+=i2-m-1;
            }
        }
        else if( i1>m && i2>r )
            break;
        else if( i1>m )
            t[i]=a[i2++];
        else if( i2>r )
        {
            t[i]=a[i1++];
            ans+=i2-m-1;
        }
    }
    for( i=l; i<=r; i++ )
        a[i]=t[i];
}

int main(){
    int i, d=0;
    while( scanf("%d", &n)==1 )
    {
        for( i=0; i<n; i++ )
            scanf("%d", &a[i]);
        ans=0;
        merge(0, n-1);
        printf("%I64d\n", ans);
    }
    return 0;
}

