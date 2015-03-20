#include <iostream>

using namespace std;

char s[10001];
unsigned int a[10001];

int main(){
    int i, slen;
    while( gets(s) && strcmp(s, "0")!=0 )
    {
        slen=strlen(s);
        for( i=0; i<slen; i++ ) a[i]=0;
        a[0]=1;
        for( i=1; i<slen; i++ )
        {
            if( s[i]!='0' ) a[i]+=a[i-1];
            if( (s[i-1]-48)*10+s[i]-48<=26 && s[i-1]!='0' )
            {
                if(i>1) a[i]+=a[i-2]; else a[i]++;
            }
        }
        printf("%d\n", a[slen-1]);
    }
    return 0;
}