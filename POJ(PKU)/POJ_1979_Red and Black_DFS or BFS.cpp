#include <cstdio>
#include <cstring>
#define MAX 22

using namespace std;

char vst[MAX][MAX];
char map[MAX][MAX];
int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
int w, h, ans;

void dfs(int x, int y)
{
	if (x < 0 || x >= h || y < 0 || y >= w) return ;
	if (!map[x][y]) return ;
	if (vst[x][y]) return ;
	
	vst[x][y] = 1;
	ans++;
	int i;
	for (i = 0; i < 4; i++)
		dfs(x + mx[i], y + my[i]);
}

int main()
{
	int i, j, sx, sy;
	char s[MAX];
	while (scanf("%d%d", &w, &h) == 2 && !(w == 0 && h == 0))
	{
		// init
		ans = 0;
		scanf("\n");
		memset(vst, 0, sizeof(vst));
		
		// input
		for (i = 0; i < h; i++)
		{
			gets(s);
			for (j = 0; j < w; j++)
				if (s[j] == '@')
				{
					sx = i;
					sy = j;
					map[sx][sy] = 1;
				}
				else
					map[i][j] = s[j] == '.';
		}
		
		// start
		dfs(sx, sy);
		
		printf("%d\n", ans);
	}
	return 0;
}
