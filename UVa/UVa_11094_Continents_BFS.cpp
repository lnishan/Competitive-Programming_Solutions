#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int M = 22, N = 22;
int r, c;
int m[M][N], chk[M][N];
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
char s[102];

inline bool valid(const int &x, const int &y)
{
	return x >= 0 && x < r && y >= 0 && y < c;
}

int bfs(const int &x, const int &y)
{
	int i, j, nx, ny, ret = 1;
	queue<pair<int, int> > q;
	chk[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int &qx = q.front().first;
		int &qy = q.front().second;
		for (i = 0; i < 4; i++)
		{
			nx = qx + mx[i];
			ny = ((qy + my[i]) + c) % c;
			if (valid(nx, ny) && !chk[nx][ny] && m[nx][ny])
			{                  
				chk[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				ret++;
			}
		}
		q.pop();
	}
	return ret;
}

int main()
{
	int i, j, x, y;
	int ans;
	while (scanf("%d%d", &r, &c) == 2)
	{
		ans = 0;
		memset(chk, 0, sizeof(chk));
		for (i = 0; i < r; i++)
		{
			scanf(" ");
			gets(s);
			for (j = 0; j < c; j++)
				m[i][j] = s[j];
		}
		scanf("%d%d", &x, &y);
		char ch = m[x][y];
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				m[i][j] = m[i][j] == ch;
		bfs(x, y);
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				if (!chk[i][j] && m[i][j])
					ans = max(ans, bfs(i, j));
		printf("%d\n", ans);
	}
	return 0;
}
