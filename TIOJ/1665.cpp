#include <iostream>

using namespace std;

int main(){
    char s[100];
    int i, l;
    while( gets(s) )
    {
        l=strlen(s);
        for( i=0; i<l&&s[i]==48; i++ ) ;
        printf("%d\n", l-i);
    }
    return 0;
}