#include <iostream>

using namespace std;

int lis[100000], l=0;

int main(){
    int i, n, a, low, mid, high;
    scanf("%d%d", &n, &a);
    lis[l++]=a;
    for( i=1; i<n; i++ )
    {
        scanf("%d", &a);
        if( a>lis[l-1] )
            lis[l++]=a;
        else
        {
            low=0; high=l;
            while( high-low>1 )
            {
                mid=(low+high)/2;
                if( lis[mid]<=a )
                    low=mid;
                else
                    high=mid;
            }
            if( low ) lis[low+1]=a;
            else if( lis[0]<a ) lis[1]=a;
            else lis[0]=a;
        }
    }
    printf("%d", l);
    //while(1);
    return 0;
}