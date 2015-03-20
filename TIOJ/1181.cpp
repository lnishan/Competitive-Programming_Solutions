#include <iostream>

using namespace std;

int main(){
    char ch[91];    // RGBYP
    int i, j, t, ans;
    char s[8];
    
    scanf("%d", &t);
    gets(s);
    while( t-- )
    {
        memset(ch, 0, sizeof(ch));
        ans=0;
        gets(s);
        for( i=0; i<12; i++ )
        {
            gets(s);
            for( j=0; j<6; j++ )
                if( s[j]>=65 && s[j]<=90 ) ch[s[j]]=1;
        }
        if( ch['R'] ) ans++;
        if( ch['G'] ) ans++;
        if( ch['B'] ) ans++;
        if( ch['Y'] ) ans++;
        if( ch['P'] ) ans++;
        printf("%d\n", ans);
    }
    //while(1);
    return 0;
}