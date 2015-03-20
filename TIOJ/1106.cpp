#include <iostream>

using namespace std;

char s[100001];
int maxd, totl, maxs;

void DFS(int d, int l, int r){
    int i, j, ts=0, mst;
    maxd=max(maxd, d);
    for( i=l; i<=r; i++ )
        if( s[i]=='*' )
            ts++;
        else
        {
            ts++;
            mst=1;
            for( j=i+1; j<=r; j++ )
            {
                if( s[j]=='(' )
                    mst++;
                else if( s[j]==')' )
                    mst--;
                if( mst==0 ) break;
            }
            DFS(d+1, i+1, j-1);
            i=j;
        }
    maxs=max(maxs, ts);
    return ;
}

int main(){
    int i, j, l;
    while( gets(s) )
    {
        maxd=totl=maxs=0;
        l=strlen(s);
        for( i=0; i<l; i++ )
            totl+=(s[i]=='*');
        DFS(1, 0, l-1);
        printf("%d %d %d\n", totl, maxd, maxd==1?0:maxs);
    }
    return 0;
}