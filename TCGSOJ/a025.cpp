#include <iostream>

using namespace std;

char s[101];
int main(){
    int i, l;
    while( gets(s) )
    {
        l=strlen(s);
        for( i=l-1; i>=0; i-- )
            putchar(s[i]);
        putchar('\n');
    }
    return 0;
}
