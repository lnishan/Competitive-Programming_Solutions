#include <iostream>

using namespace std;

char u[91];
char getCh(int ind){
    int i, j, li=0;
    for( i=0; i<=ind; i++ )
    {
        for( j=li; j<26; j++ )
            if( !u[65+j] )
            {
                li=j+1;
                break;
            }
    }
    return 64+li;
}

int main(){
    int i, n, m, fact[13], t;
    char c;
    fact[0]=1; for( i=1; i<=12; i++ ) fact[i]=fact[i-1]*i;
    while( scanf("%d%d", &n, &m) && (n!=0||m!=0) )
    {
        for( i=65; i<=90; i++ ) u[i]=0;
        m%=fact[n];
        if( m==0 ) m+=fact[n];
        m--;
        for( i=n-1; i>0; i-- )
        {
            c=getCh(m/fact[i]);
            printf("%c ", c);
            u[c]=1;
            m%=fact[i];
        }
        printf("%c\n", getCh(m));
    }
    return 0;
}