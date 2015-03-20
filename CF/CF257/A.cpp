#include <cstdio>
#include <deque>

using namespace std;

struct node{ int id, n; } tmp;
deque<node> q;

int main()
{
	int i, n, m, cn;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &cn);
		q.push_back( (node){i, cn} );
	}
	while ( !q.empty() )
	{
		tmp = q.front();
		if (tmp.n <= m)
			q.pop_front();
		else
		{
			tmp.n -= m;
			q.pop_front();
			q.push_back(tmp);
		}
	}
	printf("%d\n", tmp.id);
	return 0;
}
