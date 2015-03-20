#include <iostream>

using namespace std;

char s1[1001], s2[1001];
int a[1001][1001];

int main(){
    int i, j, l1, l2, cost;
    for( i=0; i<1000; i++ ) a[i][0]=a[0][i]=i;
    gets(s1); l1=strlen(s1);
    gets(s2); l2=strlen(s2);
    for( i=1; i<=l1; i++ )
        for( j=1; j<=l2; j++ )
        {
            if( s1[i-1]==s2[j-1] ) cost=0; else cost=1;
            a[i][j]=min(a[i-1][j]+1, a[i][j-1]+1);
            a[i][j]=min(a[i][j], a[i-1][j-1]+cost);
        }
    printf("%d", a[l1][l2]);
    //while(1);
    return 0;
}