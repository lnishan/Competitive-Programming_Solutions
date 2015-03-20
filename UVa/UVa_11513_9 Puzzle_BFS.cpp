#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#define N 3
#define MAX 202

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
					return board[i][j] < rhs.board[i][j];
		return false;
	}
};

state goal;
map<state, int> nxt;
map<state, int> stp;
map<state, int>::iterator it;
queue<state> q;

void init()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			goal.board[i][j] = i * N + j + 1;
}

void preprocess()
{
	int i, qstp, t0, t2;
	state tmp;
	nxt.clear();
	stp.clear();
	while (!q.empty()) q.pop();
	nxt[goal] = -1;
	stp[goal] = 0;
	q.push(goal);
	while (!q.empty())
	{
		state &qi = q.front();
		qstp = stp[qi];
			
		// row
		for (i = 0; i < 3; i++)
		{
			tmp = qi;
			t0 = tmp.board[i][0];
			tmp.board[i][0] = tmp.board[i][1];
			tmp.board[i][1] = tmp.board[i][2];
			tmp.board[i][2] = t0;
			
			it = stp.find(tmp);
			if (it == stp.end())
			{
				stp[tmp] = qstp + 1;
				nxt[tmp] = /* 0 * (1 << 2) | */ i;
				q.push(tmp);
			}
		}
		
		//col
		for (i = 0; i < 3; i++)
		{
			tmp = qi;
			t2 = tmp.board[2][i];
			
			tmp.board[2][i] = tmp.board[1][i];
			tmp.board[1][i] = tmp.board[0][i];
			tmp.board[0][i] = t2;
			it = stp.find(tmp);
			if (it == stp.end())
			{
				stp[tmp] = qstp + 1;
				nxt[tmp] = (1 << 2) | i;
				q.push(tmp);
			}
		}
		
		q.pop();
	}
}

int main()
{
	int i, j, k, qstp, t2, t0, ans, nxtStp, row, col;
	state st, tmp, cur;
	init();
	preprocess();
	while (scanf("%d", &st.board[0][0]) == 1 && st.board[0][0] > 0)
	{
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{
				if ((i | j) == 0) continue;
				scanf("%d", &st.board[i][j]);
			}
		it = stp.find(st);
		if ( it == stp.end() )
			puts("Not solvable");
		else
		{
			printf("%d ", stp[st]);
			cur = st;
			while ( (nxtStp = nxt[cur]) != -1 )
			{
				if (nxtStp & (1 << 2)) // col
				{
					col = nxtStp & 3;
					t0 = cur.board[0][col];
					cur.board[0][col] = cur.board[1][col];
					cur.board[1][col] = cur.board[2][col];
					cur.board[2][col] = t0;
					
					printf("V%d", col+1);
				}
				else
				{
					row = nxtStp & 3;
					t2 = cur.board[row][2];
					cur.board[row][2] = cur.board[row][1];
					cur.board[row][1] = cur.board[row][0];
					cur.board[row][0] = t2;
					
					printf("H%d", row+1);
				}
			}
			puts("");
		}
	}
	return 0;
}
