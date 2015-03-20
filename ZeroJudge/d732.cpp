#include <cstdio>

using namespace std;

inline int input(){
    char c, m=0;
    for( c=getchar(); c<48||c>57; c=getchar() ) if( c=='-' ) m=1;
    int x=c-48;
    for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
    if( m ) return -x; else return x;
}

int a[100000], n, k;

int bs(int q){
    int l=0, m, h=n;
    while( h-l>1 )
    {
        m=(l+h)/2;
        if( a[m]<=q )
            l=m;
        else
            h=m;
    }
    return l;
}

int main(){
    int i, q, qi;
    n=input();
    k=input();
    for( i=0; i<n; i++ )
        a[i]=input();
    while( k-- )
    {
        q=input();
        qi=bs(q);
        if( a[qi]==q )
            printf("%d\n", qi+1);
        else
            puts("0");
    }
    return 0;
}
