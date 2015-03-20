#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int i, n, ans;
    double sq;
    while( scanf("%d", &n)==1 )
    {
        ans=1;
        sq=sqrt(n);
        for( i=2; i<sq; i++ )
            if( n%i==0 )
                ans+=i+(n/i);
        if( sq*sq==n ) ans+=sq;
        if( ans<n )
            puts("Deficient");
        else if( ans==n )
            puts("Perfect");
        else
            puts("Abundant");
    }
    return 0;
}
