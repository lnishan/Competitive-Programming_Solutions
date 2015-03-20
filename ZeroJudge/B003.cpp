#include<iostream>
#include<math.h>

using namespace std;
int main(){
    int k,c,n;
    while(scanf("%d",&k)==1)
    {
        if( k < 0 ) k=-k;
        n=( sqrt( 8*k+1 )-1 ) / 2;
        if( n*(n+1)/2 != k ){
            c=(n+1)*(n+2)/2-k;
            if( c%2 == 1 ){
                n+=2;
                if(n%2==0) n++;
            }else n++;
        }
        printf("%d\n",n);
    }
    return 0;
}