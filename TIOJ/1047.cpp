#include <iostream>

using namespace std;

int main(){
    char s[100], ts[100], *ptr;
    int i, j, k, a[100], ac, l, n, sl, t;
    while( gets(s) && strcmp(s, "END")!=0 )
    {
        ac=0; sl=strlen(s);
        for( i=0; i<sl; i++ ) ts[i]=s[i]; ts[sl]='\0';
        ptr=strtok(ts, "*+");
        while( ptr!=NULL )
        {
            l=strlen(ptr);
            if( l%2 )
                a[ac++]=ptr[l-1]-48;
            else
                a[ac++]=1-(ptr[l-1]-48);
            ptr=strtok(NULL, "*+");
        }
        for( i=0,j=1; i<sl,j<ac; i++ )
            if( s[i]=='*' )
            {
                t=j-1;
                n=a[j-1];
                for( k=i; k<sl; k++ )
                    if( s[k]=='*' )
                    {
                        n=(n&&a[j]);
                        a[j]=-1;
                        j++;
                    }
                    else if( s[k]=='+' )
                        break;
                a[t]=n;
                i=k-1;
            }
            else if( s[i]=='+' )
                j++;
        n=a[0];
        for( i=1; i<ac; i++ )
            if( a[i]>=0 )
                n=(n||a[i]);
        printf("%d\n", n);
    }
    return 0;
}