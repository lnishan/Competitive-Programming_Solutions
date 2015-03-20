#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

char s[20], *ptr;

int main(){
    int i, l, a;
    long long int n;
    while( gets(s) )
    {
        l=strlen(s);
        ptr=strtok(s, ".");
        n=atoi(ptr)*10000;
        ptr=strtok(NULL, ".");
        n+=atoi(ptr)*100;
        if( n<1000000 ) a=80000; else a=0;
        if( n>=100 && n<=1000000 )
            n=n*90/100;
        else if( n>=1000001 && n<=5000000 )
            n=n*80/100;
        else
            n=n*60/100;
        n+=a;
        printf("$%lld.%02lld\n", n/10000, (n/100)%100);
    }
    return 0;
}   
