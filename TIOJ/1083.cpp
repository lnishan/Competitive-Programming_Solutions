#include <iostream>

using namespace std;

char s[43][110000];

int main(){
    int i, j, k, slen, slen2, c, n;
    strcat(s[1], "1");
    for( i=2; i<43; i++ )
    {
        slen=strlen(s[i-1]);
        slen2=0;
        for( j=0; j<slen; j+=c,slen2+=2 )
        {
            c=1;
            for( k=j+1; k<slen; k++ )
                if( s[i-1][j]==s[i-1][k] )
                    c++;
                else
                    break;
            s[i][slen2]=c+48;
            s[i][slen2+1]=s[i-1][j];
        }
        s[i][slen2]='\0';
    }
    while( scanf("%d", &n) && n>0 )
    {
        slen=strlen(s[n-1]);
        slen2=strlen(s[n]);
        printf("%d %.6lf\n", slen2, double(slen)/slen2);
    }
    return 0;
}