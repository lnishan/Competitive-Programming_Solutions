#include <cstdio>
#include <cstring>

using namespace std;

int mat[31][2][2];
long long int m[2];

void t( int q ){
    int i, j, k;
    for( i=0; i<2; i++ )
        for( j=0; j<2; j++ )
            for( k=0; k<2; k++ )
            {
                mat[q][i][j]+=mat[q-1][i][k]*mat[q-1][k][j];
                mat[q][i][j]%=10007;
            }
}

void t2( int q ){
    int i, j, k, t;
    t=m[0];
    m[0]=mat[q][0][0]*m[0]+mat[q][0][1]*m[1];
    m[1]=mat[q][1][0]*t   +mat[q][1][1]*m[1];
    m[0]%=10007;
    m[1]%=10007;
}

int main(){
    int i, n;
    memset(mat, 0, sizeof(mat));
    mat[0][0][1]=mat[0][1][0]=mat[0][1][1]=1;
    for( i=1; i<=30; i++ )
        t(i);
    /*
    for( i=0; i<=30; i++ )
    {
        printf("%d %d\n", mat[i][0][0], mat[i][0][1]);
        printf("%d %d\n\n", mat[i][1][0], mat[i][1][1]);
    }
    */
    while( scanf("%d", &n)==1 )
    {
        m[0]=0; m[1]=1;
        for( i=0; n>0; i++ )
        {
            if( n%2 )
                t2(i);
            n/=2;
        }
        printf("%lld\n", m[1]);
    }
    return 0;
}
