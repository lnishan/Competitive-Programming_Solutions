/* 
exactly 5
left right both check 5
note checking order : col1 -> col2 -> col3*/

#include <cstdio>

using namespace std;

// 8-neighbor . opposite direction(i) = 7 - i
int mx[8] = {0, -1, -1, -1, 1, 1, 1, 0};
int my[8] = {1, 1, 0, -1, 1, 0, -1, -1};
int map[20][20];

inline bool valid(int n)
{
	return n >= 1 && n <= 19;
}

int main()
{
	int i, j, k, x, y, t, cntL, cntR;
	bool won;
	scanf("%d", &t);
	while (t--)
	{
		//init
		won = false;
		
		// input
		for (i = 1; i <= 19; i++)
			for (j = 1; j <= 19; j++)
				scanf("%d", &map[i][j]);
		
		// start
		for (j = 1; j <= 19 && !won; j++)
			for (i = 1; i <= 19 && !won; i++)
				if (map[i][j] > 0) // has stone
				{
					for (k = 0; k < 4; k++)
					{
						cntL = cntR = 0;
						for (x = i, y = j; valid(x) && valid(y) && map[x][y] == map[i][j]; x += mx[k], y += my[k])
							cntL++;
						for (x = i, y = j; valid(x) && valid(y) && map[x][y] == map[i][j]; x += mx[7-k], y += my[7-k])
							cntR++;
						if (cntL + cntR - 1 == 5)
						{
							won = true;
							printf("%d\n", map[i][j]);
							printf("%d %d\n", i, j);
							break;
						}
					}
				}
		
		if (!won) // nobody wins
			puts("0");
	}
	return 0;
}
