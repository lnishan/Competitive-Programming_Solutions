#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1000001];
int c[1000001];

inline int input(){
    char c;
    for( c=getchar(); c<48||c>57; c=getchar() ) ;
    int x=c-48;
    for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
    return x;
}

int main(){
    int i, j, n, m, a, ans=0, s;
    n=input(); m=input();
    for( i=2; i<=n; i++ )
    {
        a=input();
        v[a].push_back(i);
    }
    for( i=n; i>=1; i-- )
    {
        c[i]=0;
        s=v[i].size();
        for( j=0; j<s; j++ )
            c[i]=max(c[i], c[v[i][j]]+1);
        if( c[i]<m ) ans++;
    }
    printf("%d", ans);
    //while(1);
    return 0;
}