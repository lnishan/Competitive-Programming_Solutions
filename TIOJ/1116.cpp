#include <iostream>

using namespace std;

int main(){
    char s[5];
    bool printed;
    int i;
    while( gets(s) )
    {
        for( i=0; i<4; i++ )
        {
            if( i>0 ) printf(", ");
            if( s[i]=='b' )
                printf("X");
            else
            {
                printed=false;
                if( s[((i-1)+4)%4]=='b' || s[((i-1)+4)%4]=='c' )
                { printf("A"); printed=true; }
                if( s[(i+1)%4]=='b' || s[(i+1)%4]=='c' )
                { printf("B"); printed=true; }
                if( s[(i+2)%4]=='b' || s[(i+2)%4]=='c' )
                { printf("C"); printed=true; }
                if( !printed ) printf("Y");
            }
        }
        putchar('\n');
    }
    return 0;
}