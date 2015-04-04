#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int W = 202, H = 202;

int w, h;
char m[W][H];
char s[210];

int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
int state[W][H];
int cnt_1, cnt_0;
char outside[W * H];

char ch[10] = {'W', 'A', 'K', 'J', 'S', 'D'};
vector<char> ans;

inline int dec(const char &c)
{
	return c <= '9' ? c-'0' : c-'a'+10;
}

inline bool valid(int &x, int &y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}

bool bfs_0(const int &x, const int &y)
{
	int i, j, nx, ny;
	queue<pair<int, int> > q;
	while (!q.empty()) q.pop();
	state[x][y] = -(++cnt_0);
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int &qx = q.front().first;
		int &qy = q.front().second;
		for (i = 0; i < 4; i++)
		{
			nx = qx + mx[i];
			ny = qy + my[i];
			if (!valid(nx, ny)) outside[-state[x][y]] = 1;
			if (!valid(nx, ny) || state[nx][ny]) continue;
			if (m[nx][ny] == 0)
			{
				state[nx][ny] = state[qx][qy];
				q.push(make_pair(nx, ny));
			}
		}
		q.pop();
	}
	return outside[-state[x][y]];
}

int bfs_1(const int &x, const int &y)
{
	int i, j, nx, ny, cnt = 0;
	queue<pair<int, int> > q;
	while (!q.empty()) q.pop();
	state[x][y] = ++cnt_1;
	q.push(make_pair(x, y));
	while (!q.empty())
	{
		int &qx = q.front().first;
		int &qy = q.front().second;
		for (i = 0; i < 4; i++)
		{
			nx = qx + mx[i];
			ny = qy + my[i];
			if (!valid(nx, ny) || state[nx][ny]) continue;
			if (m[nx][ny])
			{
				state[nx][ny] = state[qx][qy];
				q.push(make_pair(nx, ny));
			}
			else
			{
				if (!bfs_0(nx, ny)) // inside
					cnt++;
			}
		}
		q.pop();
	}
	return cnt;
}

int main()
{
	int i, j, k, cases = 0;
	int n;
	while (scanf("%d%d", &h, &w) == 2 && (w | h))
	{
		cnt_1 = cnt_0 = 0;
		memset(state, 0, sizeof(state));
		memset(outside, 0, sizeof(outside));
		ans.clear();
		for (i = 0; i < h; i++)
		{
			scanf(" ");
			gets(s);
			for (j = 0; j < w; j++)
			{
				n = dec(s[j]);
				for (k = 3; k >= 0; k--, n >>= 1)
					m[i][j*4 + k] = n & 1;
			}
		}
		w *= 4;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (!state[i][j] && m[i][j] == 1)
					ans.push_back( ch[bfs_1(i, j)] );
		sort(ans.begin(), ans.end());
		printf("Case %d: ", ++cases);
		for (i = 0; i < ans.size(); i++)
			putchar(ans[i]);
		puts("");
	}
	return 0;
}
