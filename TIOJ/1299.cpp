#include <iostream>

using namespace std;

int main(){
    char s[100];
    int i, l, sum;
    while( gets(s) )
    {
        l=strlen(s);
        sum=0;
        for( i=0; i<l; i++ )
            if( isupper(s[i]) )
                sum+=s[i]-64;
            else
                sum+=s[i]-96;
        sum%=17;
        if( sum>=0 && sum<=2 )
            puts("D");
        else if( sum>=3 && sum<=5 )
            puts("C");
        else if( sum>=6 && sum<=9 )
            puts("B");
        else if( sum>=10 && sum<=12 )
            puts("A");
        else
            puts("SA");
    }
    return 0;
}