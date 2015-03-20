#include <cstdio>
#define N 100002
#define N_DBL 200005

using namespace std;

int set[N_DBL];

int set_find(int i)
{
	if( set[i]==i )
		return i;
	else
		return set[i]=set_find(set[i]);
}

int main()
{
	int i, j, k, t, n, m, a, b, fa, fb;
	char c;
	scanf("%d", &t);
	while( t-- )
	{
		scanf("%d%d", &n, &m);
		for( i=1; i<=n; i++ )
		{
			set[i]=i;
			set[N+i]=N+i;
		}
		while( m-- )
		{
			scanf("\n");
			scanf("%c %d %d", &c, &a, &b);
			if( c=='D' )
			{
				set[set_find(a)]=set_find(N+b);
				set[set_find(b)]=set_find(N+a);
			}
			else
			{
				fa=set_find(a);
				fb=set_find(b);
				if( fa==fb )
					puts("In the same gang.");
				else if( fa==set_find(b+N) )
					puts("In different gangs.");
				else
					puts("Not sure yet.");
			}
		}
	}
	return 0;
}