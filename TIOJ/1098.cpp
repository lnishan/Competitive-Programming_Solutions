#include <iostream>
#include <queue>

using namespace std;

struct node{
    int a, b, c;
} tmp;
queue<node> q;
int mstp[101][101][101];

int main(){
    int a, b, c, gcd, ta, tb, qa, qb, qc;
    while( scanf("%d%d%d", &a, &b, &c)==3 && !(a==0 && b==0 && c==0) )
    {
        ta=a; tb=b;
        while( ta>0 && tb>0 )
            if( ta>tb )
                ta%=tb;
            else
                tb%=ta;
        gcd=(ta==0)?tb:ta;
        if( c%gcd!=0 )
            puts("No");
        else
        {
            memset(mstp, -1, sizeof(mstp));
            mstp[0][0][c]=0;
            tmp.a=0; tmp.b=0; tmp.c=c;
            q.push(tmp);
            while( !q.empty() )
            {
                qa=q.front().a;
                qb=q.front().b;
                qc=q.front().c;
                //1
                if( mstp[0][qb][qc]<0 )
                {
                    mstp[0][qb][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=0; tmp.b=qb; tmp.c=qc;
                    q.push(tmp);
                }
                if( mstp[qa][0][qc]<0 )
                {
                    mstp[qa][0][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=qa; tmp.b=0; tmp.c=qc;
                    q.push(tmp);
                }
                //2
                if( mstp[a][qb][qc]<0 )
                {
                    mstp[a][qb][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=a; tmp.b=qb; tmp.c=qc;
                    q.push(tmp);
                }
                if( mstp[qa][b][qc]<0 )
                {
                    mstp[qa][b][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=qa; tmp.b=b; tmp.c=qc;
                    q.push(tmp);
                }
                //3
                if( qa+qb<=a && mstp[qa+qb][0][qc]<0 )
                {
                    mstp[qa+qb][0][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=qa+qb; tmp.b=0; tmp.c=qc;
                    q.push(tmp);
                }
                if( qb+qa<=b && mstp[0][qb+qa][qc]<0 )
                {
                    mstp[0][qb+qa][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=0; tmp.b=qb+qa; tmp.c=qc;
                    q.push(tmp);
                }
                //4
                if( (a-qa)<=qb && mstp[a][qb-(a-qa)][qc]<0 )
                {
                    mstp[a][qb-(a-qa)][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=a; tmp.b=qb-(a-qa); tmp.c=qc;
                    q.push(tmp);
                }
                if( (b-qb)<=qa && mstp[qa-(b-qb)][b][qc]<0 )
                {
                    mstp[qa-(b-qb)][b][qc]=mstp[qa][qb][qc]+1;
                    tmp.a=qa-(b-qb); tmp.b=b; tmp.c=qc;
                    q.push(tmp);
                }
                //5
                if( qc>=qa && mstp[0][qb][qc-qa]<0 )
                {
                    mstp[0][qb][qc-qa]=mstp[qa][qb][qc]+1;
                    tmp.a=0; tmp.b=qb; tmp.c=qc-qa;
                    if( tmp.c==0 ) break;
                    q.push(tmp);
                }
                if( qc>=qb && mstp[qa][0][qc-qb]<0 )
                {
                    mstp[qa][0][qc-qb]=mstp[qa][qb][qc]+1;
                    tmp.a=qa; tmp.b=0; tmp.c=qc-qb;
                    if( tmp.c==0 ) break;
                    q.push(tmp);
                }
                q.pop();
            }
            if( tmp.c!=0 )
                puts("No");
            else
                printf("%d\n", mstp[tmp.a][tmp.b][0]);
            while( !q.empty() ) q.pop();
        }
    }
    return 0;
}