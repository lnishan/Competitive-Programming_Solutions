#include <iostream>

using namespace std;

int a[29][29];
int main(){
    int i, j, r, c;
    memset(a, 0, sizeof(a));
    a[1][1]=1;
    for( i=1; i<=28; i++ )
        for( j=1; j<=i; j++ )
        {
            a[i+1][j]+=a[i][j];
            a[i+1][j+1]+=a[i][j];
        }
    scanf("%d%d", &r, &c);
    printf("%d", a[r][c]*r);
    //while(1);
    return 0;
}