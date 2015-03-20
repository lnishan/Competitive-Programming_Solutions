#include <iostream>
#include <vector>

using namespace std;

int match[2][501];
char v[501];
vector<int> r[2][501];

bool augment(int t, int ii){
    int i, s=r[t][ii].size();
    v[ii]=1;
    for( i=0; i<s; i++ )
        if( match[1-t][r[t][ii][i]]==0 || (!v[match[1-t][r[t][ii][i]]] && augment(t, match[1-t][r[t][ii][i]])) )
        {
            match[t][ii]=r[t][ii][i];
            match[1-t][r[t][ii][i]]=ii;
            return true;
        }
    return false;
}

int main(){
    int t, i, j, n, k, a, b, ans=0;
    scanf("%d%d", &n, &k);
    while( k-- )
    {
        scanf("%d%d", &a, &b);
        r[0][a].push_back(b);
        r[1][b].push_back(a);
    }
    memset(match, 0, sizeof(match));
    for( t=0; t<2; t++ )
    {
        for( i=1; i<=n; i++ )
            if( match[t][i]==0 )
            {
                for( j=1; j<=n; j++ ) v[j]=0;
                if( augment(t, i) ) ans++;
            }
    }
    printf("%d", ans);
    //cin>>n;
    return 0;
}
