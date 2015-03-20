#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#define N 4

using namespace std;

struct state
{
	int board[N][N];
	bool operator < (const state &rhs)const
	{
		int i, j;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (board[i][j] != rhs.board[i][j])
					return  board[i][j] < rhs.board[i][j];
		return false;
	}
};

map<state, char> stp;
map<state, char>::iterator it;
queue<state> q;
int sz;
char wall[N][N]; // &1 => right // &2 => top // &4 => left // &8 => right
int mx[4] = {0, -1, 0, 1};
int my[4] = {1, 0, -1, 0};

/* debug */
void print(state &s)
{
	int i, j;
	for (i = 0; i < sz; i++, puts(""))
		for (j = 0; j < sz; j++)
			printf("%d ", s.board[i][j]);
}

inline bool valid(const int &n) { return n >= 0 && n < sz; }

bool isGoal(state &s)
{
	int i, j;
	for (i = 0; i < sz; i++)
		for (j = 0; j < sz; j++)
			if (s.board[i][j] != 0)
				return false;
	return true;
}

bool fall(state &s, int dir)
{
	int i, j, nx, ny;
	bool fell;
	do
	{
		fell = false;
		for (i = 0; i < sz; i++)
			for (j = 0; j < sz; j++)
			{
				int &cur = s.board[i][j];
				if (cur > 0 && !(wall[i][j] & (1 << dir))) // is a ball
				{
					nx = i + mx[dir];
					ny = j + my[dir];
					if (valid(nx) && valid(ny))
					{
						int &nxt = s.board[nx][ny];
						if (cur + nxt == 0) // dropped into a correct hole
						{
							cur = nxt = 0;
							fell = true;
						}
						else if (nxt == 0) // is an empty space
						{
							nxt = cur;
							cur = 0;
							fell = true;
						}
						else if (nxt < 0) // wrong hole
							return false;
					}
				}
			}
	} while (fell);
	return true;
}

int main()
{
	int i, j, cases = 0, m, w, x, y, x2, y2, ans, qstp;
	state st, tmp;
	while (scanf("%d%d%d", &sz, &m, &w) == 3 && (sz | m | w))
	{
		// init
		memset(wall, 0, sizeof(wall));
		memset(st.board, 0, sizeof(st.board));
		while (!q.empty()) q.pop();
		stp.clear();
		ans = -1;
		
		// input
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			st.board[x][y] = i;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			st.board[x][y] = -i;
		}
		while (w--)
		{
			scanf("%d%d%d%d", &x, &y, &x2, &y2);
			if (y < y2) // right
			{
				wall[x][y] |= 1 << 0;
				wall[x2][y2] |= 1 << 2;
			}
			else if (x2 < x) // top
			{
				wall[x][y] |= 1 << 1;
				wall[x2][y2] |= 1 << 3;
			}
			else if (y2 < y) // left
			{
				wall[x][y] |= 1 << 2;
				wall[x2][y2] |= 1 << 0;
			}
			else if (x < x2) // bot
			{
				wall[x][y] |= 1 << 3;
				wall[x2][y2] |= 1 << 1;
			}
		}
		
		
		// start
		stp[st] = 0;
		q.push(st);
		while (!q.empty())
		{
			state &qi = q.front();
			qstp = stp[qi];
			if (isGoal(qi)) { ans = qstp; break; }
			for (i = 0; i < 4; i++)
			{
				tmp = qi;
				if (fall(tmp, i))
				{
					it = stp.find(tmp);
					if (it == stp.end())
					{
						stp[tmp] = qstp + 1;
						q.push(tmp);
					}
				}
			}
			q.pop();
		}
		
		// output
		printf("Case %d: ", ++cases);
		if (ans != -1) printf("%d moves\n", ans); else puts("impossible");
		puts("");
	}
	return 0;
}
