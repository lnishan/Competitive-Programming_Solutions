#include <iostream>

using namespace std;

char s[1000];
int len,i;

int main(){
    while(gets(s))
    {
        len=strlen(s);
        for(i=0;i<len;i++)
            if( !( isalnum(s[i]) || ispunct(s[i]) || isspace(s[i]) ) )
                putchar(s[i]);
        putchar('\n');
    }
    return 0;
}