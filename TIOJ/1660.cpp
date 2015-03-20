#include <iostream>

using namespace std;

char s[32];

int main(){
    int i, slen;
    bool ispalin;
    while( scanf("%s", &s)==1 )
    {
        ispalin=true;
        slen=strlen(s);
        for( i=0; i<slen/2; i++ )
            if( s[i]!=s[slen-i-1] )
            {
                ispalin=false;
                break;
            }
        puts( ispalin?"palindrome":"not palindrome" );
    }
    return 0;
}