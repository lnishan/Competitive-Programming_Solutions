#include <iostream>

using namespace std;

char s[1025];
int main(){
    int i, t, l, alp, lns, wds, chs;
    scanf("%d\n", &t);
    while( t-- )
    {
        lns=wds=chs=0;
        while( gets(s) && strcmp(s, "=====")!=0 )
        {
            lns++;
            l=strlen(s);
            chs+=l;
            for( i=0,alp=0; i<l; i++ )
            {
                if( s[i]>' ' )
                {
                    if( !alp ){ wds++; alp=1; }
                }
                else alp=0;
            }
        }
        printf("%d %d %d\n", lns, wds, chs);
    }
    return 0;
}