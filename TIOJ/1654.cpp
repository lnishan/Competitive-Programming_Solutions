#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1000001];
int m, ans=0;

int DFS(int f){
    int i, s=v[f].size(), d=0;
    for( i=0; i<s; i++ )
        d=max(d, DFS(v[f][i])+1);
    if( d<m ) ans++;
    return d;
}

int main(){
    int i, n, a;
    scanf("%d%d", &n, &m);
    for( i=2; i<=n; i++ )
    {
        scanf("%d", &a);
        v[a].push_back(i);
    }
    DFS(1);
    printf("%d", ans);
    //while(1);
    return 0;
}