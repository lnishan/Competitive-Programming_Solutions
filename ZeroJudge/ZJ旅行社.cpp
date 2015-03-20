#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10000];
int n;

int DFS(int ind){
    int i, s=v[ind].size(), maxd=0;
    if( s==0 ) return 1;
    for( i=0; i<s; i++ )
        maxd=max(maxd, DFS(v[ind][i]));
    return maxd+1;
}

int main(){
    int i, j, a, maxd, maxd2, tmp;
while( scanf("%d", &n)==1 )
{
    maxd=maxd2=0;
    for( i=0; i<n; i++ )
        while( scanf("%d", &a)==1 && a!=-1 )
            v[i].push_back(a);
    for( i=0; i<v[0].size(); i++ )
    {
        tmp=DFS(v[0][i]);
        if( tmp>maxd )
        {
            maxd2=maxd;
            maxd=tmp;
        }
        else if( tmp>maxd2 )
            maxd2=tmp;
    }
    printf("%d\n", maxd+maxd2);
    for( i=0; i<n; i++ ) v[i].clear();
}
    return 0;
}