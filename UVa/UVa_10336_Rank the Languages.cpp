#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int> > q;
const int H = 1002;
const int W = 1002;

int h, w;
char m[H][W];
char s[W];
int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
int cnt[128];
vector<pair<char, int> > ans;

inline bool valid(const int &x, const int &y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}

void bfs(const int &x, const int &y)
{
	int i;
	while (!q.empty()) q.pop();
	char ch = m[x][y];
	m[x][y] = -1;
	q.push( make_pair(x, y) );
	while (!q.empty())
	{
		int &qx = q.front().first;
		int &qy = q.front().second;
		q.pop();
		for (i = 0; i < 4; i++)
		{
			int nx = qx + mx[i];
			int ny = qy + my[i];
			if (valid(nx, ny) && m[nx][ny] == ch)
			{
				m[nx][ny] = -1;
				q.push( make_pair(nx, ny) );
			}
		}
	}
}

bool cmp(pair<char, int> p1, pair<char, int> p2)
{
	if (p1.second != p2.second)
		return p1.second > p2.second;
	else
		return p1.first < p2.first;
}

int main()
{
	int i, j, tt;
	scanf("%d", &tt);
	for (int t = 1; t <= tt; t++)
	{
		ans.clear();
		memset(cnt, 0, sizeof(cnt));
		scanf("%d%d ", &h, &w);
		for (i = 0; i < h; i++)
		{
			gets(s);
			strcpy(m[i], s);
		}
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				if (m[i][j] != -1)
				{
					cnt[m[i][j]]++;
					bfs(i, j);
				}
		for (i = 'a'; i <= 'z'; i++)
			if (cnt[i])
				ans.push_back( make_pair(i, cnt[i]) );
		sort(ans.begin(), ans.end(), cmp);
		printf("World #%d\n", t);
		for (i = 0; i < ans.size(); i++)
			printf("%c: %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
