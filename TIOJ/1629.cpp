#include <iostream>

using namespace std;

short r[1001][1000];
int n, m, p[1000], pc;
bool v[1001], printed=false;

void DFS(int c){
    int i;
    if( pc==n ){
        for(i=0; i<pc; i++)
            printf("%d\n", p[i]);
        printed=true;
        return ;
    }
    for(i=1; i<=r[c][0]; i++)
        if( !v[r[c][i]] ){
            v[r[c][i]]=true;
            p[pc++]=r[c][i];
            DFS(r[c][i]);
            if( printed ) return ;
            v[r[c][i]]=false;
            pc--;
        }
}

int main(){
    int i, a, b;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
    {
        v[i]=false;
        r[i][0]=0;
    }
    for(i=0; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        r[a][++r[a][0]] =b;
        r[b][++r[b][0]] =a;
    }
    for(i=1; i<=n; i++)
        sort(r[i]+1, r[i]+r[i][0]+1);
    for(i=1; i<=n; i++)
    {
        p[0]=i;
        pc=1;
        v[i]=true;
        DFS(i);
        if( printed ) break;
        v[i]=false;
    }
    while(1);
    return 0;
}
