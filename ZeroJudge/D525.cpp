#include <iostream>

using namespace std;

char s[1000];
int a,q,sl;

bool zeroValidate(){
    sl=strlen(s);
    for(int i=0;i<sl;i++)
        if(s[i]>48) return false;
    return true;
}

int main(){
    while(gets(s) && !zeroValidate())
    {
        a=s[sl-1]-48;
        q=0;
        while(gets(s) && !zeroValidate())
            q=(q+s[sl-1]-48)%10;
        if(a==q)
            if(a%2)
                puts("2");
            else
                puts("1");
        else
            puts("0");
    }
    return 0;
}
