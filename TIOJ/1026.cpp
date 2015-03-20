#include <iostream>

using namespace std;

int bin[30];

int getBin(int n){
    int bc=0;
    while( n>0 )
    {
        bin[bc++]=n%2;
        n/=2;
    }
    return bc;
}

int main(){
    int i, n, t, tbc, bc;
    scanf("%d", &n);
    if( n==1 )
    {
        puts("1");
        printf("+");
    }
    else
    {
        tbc=getBin(n);
        t=(n-((1<<(tbc-1))+1))/ 2;
        printf("%d\n", tbc);
        bc=getBin(t);
        for( i=0; i<bc; i++ )
            printf( bin[i]?"+":"-" );
        for( i=bc; i<tbc-2; i++ )
            putchar('-');
        printf("++");
        // cout<<(1<<n)<<endl; 1<<2=4
    }
    //while(1);
    return 0;
}