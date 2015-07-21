#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 10005;

int s[N];
queue<int> q;

int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	memset(s, -1, sizeof(s));
	s[n] = 0;
	q.push(n);
	while (!q.empty())
	{
		int &qi = q.front();
		if (qi == m) break;
		if (s[qi << 1] == -1)
		{
			s[qi << 1] = s[qi] + 1;
			q.push(qi << 1);
		}
		if (s[qi - 1] == -1)
		{
			s[qi - 1] = s[qi] + 1;
			q.push(qi - 1);
		}
		q.pop();
	}
	printf("%d\n", s[m]);
	return 0;
}
