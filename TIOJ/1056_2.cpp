// 0 - , 1 O , 2 X
#include <iostream>

using namespace std;

int a[9], three[9];
char v[20000];  // 3^9

int getN(){
    int i, n=0;
    for( i=0; i<9; i++ )
        n+=a[i]*three[i];
    return n;
}

int check(){
    if( (a[0]==a[1]&&a[1]==a[2]&&a[0]==1) || (a[3]==a[4]&&a[4]==a[5]&&a[3]==1) || (a[6]==a[7]&&a[7]==a[8]&&a[6]==1) || (a[0]==a[3]&&a[3]==a[6]&&a[0]==1) || (a[1]==a[4]&&a[4]==a[7]&&a[1]==1) || (a[2]==a[5]&&a[5]==a[8]&&a[2]==1) || (a[0]==a[4]&&a[4]==a[8]&&a[0]==1) || (a[2]==a[4]&&a[4]==a[6]&&a[2]==1) )
        return 1;
    else if( (a[0]==a[1]&&a[1]==a[2]&&a[0]==2) || (a[3]==a[4]&&a[4]==a[5]&&a[3]==2) || (a[6]==a[7]&&a[7]==a[8]&&a[6]==2) || (a[0]==a[3]&&a[3]==a[6]&&a[0]==2) || (a[1]==a[4]&&a[4]==a[7]&&a[1]==2) || (a[2]==a[5]&&a[5]==a[8]&&a[2]==2) || (a[0]==a[4]&&a[4]==a[8]&&a[0]==2) || (a[2]==a[4]&&a[4]==a[6]&&a[2]==2) )
        return 2;
    else
        return 0;
}

void DFS(int turn, int stps){
    int i, j, c, N, N2;
    N=getN();
    c=check();
    if( c )
        return ;
    if( stps==9 )
        return ;
    for( i=0; i<9; i++ )
        if( a[i]==0 )
        {
            a[i]=turn;
            N2=getN();
            if( !v[N2] )
            {
                DFS((turn==1)?2:1, stps+1);
                v[N2]=1;
            }
            a[i]=0;
        }
    return ;
}

int main(){
    int i, j, oc=0, xc=0;
    char s[5];
    bool chVal=true;
    
    three[0]=1; for( i=1; i<9; i++ ) three[i]=three[i-1]*3;
    memset(v, 0, sizeof(v)); v[0]=1;
    memset(a, 0, sizeof(a));
    DFS(1, 0);
    
    
    for( i=0; i<3; i++ )
    {
        gets(s);
        for( j=0; j<3; j++ )
            if( s[j]=='.' )
                a[i*3+j]=0;
            else if( s[j]=='O' )
                a[i*3+j]=1;
            else if( s[j]=='X' )
                a[i*3+j]=2;
            else
                chVal=false;
    }
    if( !chVal || !v[getN()] )
        puts("IMPOSSIBLE");
    else
        puts("POSSIBLE");
    //while(1);
    return 0;
}