#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 102;

int n;
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
int m[N][N];
char chk[N][N];
char s[202];
queue<pair<int, int> > q;

inline bool valid(const int &x, const int &y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	int i, j, k, t;
	int nx, ny;
	int ans;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++)
	{
		ans = 0;
		while (!q.empty()) q.pop();
		memset(chk, 0, sizeof(chk));
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf(" ");
			gets(s);
			for (j = 0; j < n; j++)
				switch (s[j])
				{
					case 'x':
						m[i][j] = 1;
						break;
					case '@':
						m[i][j] = -1;
						break;
					case '.':
						m[i][j] = 0;
				}
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (m[i][j] == 1 && !chk[i][j])
				{
					ans++;
					chk[i][j] = 1;
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						int &qx = q.front().first;
						int &qy = q.front().second;
						for (k = 0; k < 4; k++)
						{
							nx = qx + mx[k];
							ny = qy + my[k];
							if (valid(nx, ny) && m[nx][ny] && !chk[nx][ny])
							{
								chk[nx][ny] = 1;
								q.push(make_pair(nx, ny));
							}
						}
						q.pop();
					}
				}
		printf("Case %d: %d\n", cases, ans);
	}
	return 0;
}
