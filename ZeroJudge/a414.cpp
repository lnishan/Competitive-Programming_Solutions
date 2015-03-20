#include <cstdio>

using namespace std;

int a[50];
int main(){
    int i, n, ac, c;
    while( scanf("%d", &n)==1 && n>0 )
    {
        ac=c=0;
        while( n>0 )
        {
            a[ac++]=n%2;
            n/=2;
        }
        a[0]++;
        for( i=0; i<ac; i++ )
            if( a[i]>1 )
            {
                a[i]-=2;
                a[i+1]++;
                c++;
            }
            else
                break;
        printf("%d\n", c);
    }
    return 0;
}
