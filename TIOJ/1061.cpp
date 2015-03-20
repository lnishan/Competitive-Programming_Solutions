// 0 - , 1 O , 2 X
#include <iostream>

using namespace std;

int a[9], three[9];
char v[20000];  // 3^9

struct result{
    int r[3];
} ans;

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

result DFS(int turn, int stps){
    int i, j, c, N, N2;
    result r, tr;
    r.r[0]=r.r[1]=r.r[2]=0;
    N=getN();
    c=check();
    if( c )
    {
        r.r[c]=1;
        return r;
    }
    if( stps==9 )
    {
        r.r[0]=1;
        return r;
    }
    for( i=0; i<9; i++ )
        if( a[i]==0 )
        {
            a[i]=turn;
            N2=getN();
            if( !v[N2] )
            {
                tr=DFS((turn==1)?2:1, stps+1);
                for( j=0; j<3; j++ ) r.r[j]+=tr.r[j];
                v[N2]=1;
            }
            a[i]=0;
        }
    return r;
}

int main(){
    int i, oc=0, xc=0, N;
    three[0]=1; for( i=1; i<9; i++ ) three[i]=three[i-1]*3;
    memset(v, 0, sizeof(v));
    v[0]=1;
    
    char s[11];
    gets(s);
    for( i=0; i<9; i++ )
        if( s[i]=='O' )
        {
            a[i]=1;
            oc++;
        }
        else if( s[i]=='X' )
        {
            a[i]=2;
            xc++;
        }
        else
            a[i]=0;
    ans.r[0]=ans.r[1]=ans.r[2]=0;
    if( oc==xc )
        ans=DFS(1, oc+xc);
    else
        ans=DFS(2, oc+xc);
    printf("%d %d %d %d", ans.r[0]+ans.r[1]+ans.r[2], ans.r[1], ans.r[2], ans.r[0]);
    //while(1);
    return 0;
}