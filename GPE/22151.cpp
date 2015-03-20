#include <cstdio>

using namespace std;

int b, p, m;

int dfs(int s)
{
    if( s==0 ) return 1%m;
    if( s==1 ) return b%m;
    int t=dfs(s/2);
    t=(t*t)%m;
    if( s%2==1 )
        return (t*(b%m))%m;
    else
        return t;
}

int main()
{
    while( scanf("%d%d%d", &b, &p, &m)==3 )
    {
		printf("%d\n", dfs(p));
    }
    return 0;
}
