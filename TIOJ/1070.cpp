#include <iostream>

using namespace std;

char s1[101], s2[101], spCh[]="~!@#$%^&*()_+|`-=\\{}[]:\";\'<>?,./ ";

int main(){
    int i, j, k, l;
    while( gets(s1), gets(s2) )
    {
        if( strcmp(s1, "END")==0  && strcmp(s2, "END")==0 ) break;
        
        l=strlen(s1);
        
        //1
        if( strcmp(s1, s2)!=0 )
        {
            puts("Password settings are not consistent.");
            goto nextData;
        }
        
        //2
        if( !(l>=8 && l<=12) )
        {
            puts("Password should contain 8 to 12 characters.");
            goto nextData;
        }
        
        //3
        for( i=0; i<l; i++ )
            if( isupper(s1[i]) )
                break;
        if( i==l )
        {
            puts("Password should contain at least one upper-case alphabetical character.");
            goto nextData;
        }
        
        //4
        for( i=0; i<l; i++ )
            if( islower(s1[i]) )
                break;
        if( i==l )
        {
            puts("Password should contain at least one lower-case alphabetical character.");
            goto nextData;
        }
        
        //5
        for( i=0; i<l; i++ )
            if( isdigit(s1[i]) )
                break;
        if( i==l )
        {
            puts("Password should contain at least one number.");
            goto nextData;
        }
        
        //6
        for( i=0; i<l; i++ )
        {
            for( j=0; j<33; j++ )
                if( s1[i]==spCh[j] )
                    break;
            if( j<33 ) break;
        }
        if( i==l )
        {
            puts("Password should contain at least one special character.");
            goto nextData;
        }
        
        //7
        for( i=0; i<l/2; i++ )
            if( s1[i]!=s1[l-i-1] )
                break;
        if( i==l/2 )
        {
            puts("Symmetric password is not allowed.");
            goto nextData;
        }
        
        //8
        bool circle;
        for( k=3; k<=6; k++ )
        {
            circle=true;
            for( i=k; i<l; i+=k )
            {
                for( j=0; j<k&&i+j<l; j++ )
                    if( s1[j]!=s1[i+j] )
                    {
                        circle=false;
                        break;
                    }
                if( !circle ) break;
            }
            if( circle ) break;
        }
        if( k<=6 )
        {
            puts("Circular password is not allowed.");
            goto nextData;
        }
        puts("Password is valid.");
        
    nextData:;
    }
    return 0;
}