#include <iostream>

using namespace std;

int a[1000][2];
int main(){
    int i, j, n, mdis=2147483647, mx, my, tdis;
    scanf("%d", &n);
    for( i=0; i<n; i++ )    
        scanf("%d%d", &a[i][0], &a[i][1]);
    for( i=0; i<n; i++ )
    {
        tdis=0;
        for( j=0; j<n; j++ )
            tdis+=abs(a[i][0]-a[j][0])+abs(a[i][1]-a[j][1]);
        if( tdis<mdis )
        {
            mdis=tdis;
            mx=a[i][0]; my=a[i][1];
        }
        else if( tdis==mdis )
        {
            if( a[i][0]<mx )
            {
                mx=a[i][0]; my=a[i][1];
            }
            else if( a[i][0]==mx )
            {
                if( a[i][1]<my )
                {
                    mx=a[i][0]; my=a[i][1];
                }
            }
        }
    }
    printf("%d %d\n", mx, my);
    printf("%d", mdis);
    //while(1);
    return 0;
}