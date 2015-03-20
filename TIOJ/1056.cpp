#include <iostream>

using namespace std;

int a[3][3];
char s[5];

bool judge(){
    int i, j, jg[3]={0}, t;
    for( i=0; i<3; i++ )
    {
        if( a[i][0]==a[i][1] && a[i][1]==a[i][2] && a[i][0]!=0 ) jg[a[i][0]]++;
        if( a[0][i]==a[1][i] && a[1][i]==a[i][2] && a[0][i]!=0 ) jg[a[0][i]]++;
    }
    if( a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]!=0 ) jg[a[0][0]]++;
    if( a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[0][2]!=0 ) jg[a[0][2]]++;
    if( jg[1]>0 && jg[2]>0 )
        return false;
    return true;
}

int main(){
    int i, j, oc=0, xc=0;
    bool valid=true;
    for( i=0; i<3; i++ )
    {
        gets(s);
        for( j=0; j<3; j++ )
            if( s[j]=='.' )
                a[i][j]=0;
            else if( s[j]=='O' )
            {
                a[i][j]=1;
                oc++;
            }
            else if( s[j]=='X' )
            {
                a[i][j]=2;
                xc++;
            }
            else
                valid=false;
    }
    if( valid )
    {
        if( oc==xc || oc==xc+1 )
            valid=judge();
        else
            valid=false;
    }
    printf(valid?"POSSIBLE":"IMPOSSIBLE");
    while(1);
    return 0;
}