#include <iostream>

using namespace std;

int main(){
    char s[101];
    int i, l;
    while( gets(s) )
    {
        l=strlen(s);
        for( i=0; i<l; i++ )
            if( isalpha(s[i]) )
            {
                if( isupper(s[i]) )
                    s[i]=s[i]+32;
                else
                    s[i]=s[i]-32;
            }
            else
                s[i]=' ';
        puts(s);
    }
    return 0;
}