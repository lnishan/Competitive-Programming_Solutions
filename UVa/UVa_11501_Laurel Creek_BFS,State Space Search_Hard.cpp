#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define MAX_STUMP 15
#define MAX_R 15
#define MAX_C 15
#define INF 0x3fffffff
#define S_NO(X) 2 + X

using namespace std;

int r, c, ss; // no of stumps
int sPos[MAX_STUMP][2];
struct state
{
	// int sPos[MAX_STUMP][2];
	int sAt; // which stump are we at ?
	int cLogs[MAX_STUMP][4]; // connected logs
	int hLogs; // number of logs holding
	bool operator < (const state &rhs)const
	{
		if (sAt != rhs.sAt)
			return sAt < rhs.sAt;
		else
		{
			int i, j;
			for (i = 0; i < ss; i++)
				for (j = 0; j < 4; j++)
					if (cLogs[i][j] != rhs.cLogs[i][j])
						return cLogs[i][j] < rhs.cLogs[i][j];
			if (hLogs != rhs.hLogs)
				return hLogs < rhs.hLogs;
		}
		return false;
	}
};
int mx[4] = {0, -1, 0, 1};
int my[4] = {1, 0, -1, 0};
int expCh[4] = {'-', '|', '-', '|'};

map<state, int> stp;
map<state, int>::iterator it;
queue<state> q;
char m[MAX_R][MAX_C];
char used[MAX_R][MAX_C];
char mp[MAX_R][MAX_C];
char qmp[MAX_R][MAX_C];

inline int valid(const int &x, const int &y)
{
	return x >= 0 && x < r 
		&& y >= 0 && y < c;
}

inline int dist(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

inline int detDir(const int &cx, const int &cy, const int &sx, const int &sy)
{
	if (cx == sx)
	{
		if (cy < sy)
			return 0;
		else
			return 2;
	}
	else if (cy == sy)
	{
		if (cx < sx)
			return 3;
		else
			return 1;
	}
}

int main()
{
	int i, j, k, t, nx, ny, dir, qstp, tmp;
	int d, minD[4], minS[4];
	char av;
	state st;
	int sEnd; // destination stump
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &r, &c);
		scanf(" ");
		for (i = 0; i < r; i++)
			gets(m[i]);
		
		stp.clear();
		ss = 0;
		st.hLogs = 0;
		while (!q.empty()) q.pop();
		memset(used, 0, sizeof(used));
		for (i = 0; i < r; i++) for (j = 0; j < c; j++) mp[i][j] = 0;
		
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
			{
				char &ch = m[i][j];
				switch (ch)
				{
					case 'S':
					case 'B':
					case 'E':
						mp[i][j] = S_NO(ss);
						sPos[ss][0] = i;
						sPos[ss][1] = j;
						if (ch == 'B')
							st.sAt = ss;
						else if (ch == 'E')
							sEnd = ss;
						for (k = 0; k < 4; k++)
						{
							st.cLogs[ss][k] = 0;
							for (nx = i + mx[k], ny = j + my[k];
								valid(nx, ny) && m[nx][ny] == expCh[k];
								nx += mx[k], ny += my[k])
							{
								used[nx][ny] = 1;
								st.cLogs[ss][k]++;
							}
						}
						ss++;
						break;
				}
			}
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				if ( (m[i][j] == '-' || m[i][j] == '|')
					&& !used[i][j] )
					mp[i][j] = 1;
		
		stp[st] = 0;
		q.push(st);
		while (!q.empty())
		{
			state &qi = q.front();
			qstp = stp[qi];
			if (qi.sAt == sEnd) break;
			int &cx = sPos[qi.sAt][0];
			int &cy = sPos[qi.sAt][1];
			
			// read state data
			for (i = 0; i < r; i++) for (j = 0; j < c; j++) qmp[i][j] = mp[i][j];
			for (i = 0; i < ss; i++)
				for (j = 0; j < 4; j++)
				{
					int &cLog = qi.cLogs[i][j];
					if (cLog)
						for (k = 1; k <= cLog; k++)
							qmp[ sPos[i][0] + mx[j] * k ][ sPos[i][1] + my[j] * k ] = 1;
				}	
			
			// traverse
			for (i = 0; i < ss; i++)
			{
				if (i == qi.sAt) continue;
				int &sx = sPos[i][0];
				int &sy = sPos[i][1];
				if (cx == sx || cy == sy)
				{
					dir = detDir(cx, cy, sx, sy);
					if (qi.cLogs[qi.sAt][dir] == dist(cx, cy, sx, sy) - 1)
					{
						tmp = qi.sAt;
						qi.sAt = i;
						if ( (it = stp.find(qi)) == stp.end() )
						{
							stp[qi] = qstp + 1;
							q.push(qi);
						}
						qi.sAt = tmp;
					}
				}
			}
			
			// Pick up
			if (qi.hLogs == 0) // not holding logs
			{
				for (i = 0; i < 4; i++)
				{
					int &cLog = qi.cLogs[qi.sAt][i];
					if (cLog)
					{
						qi.hLogs = cLog;
						
						nx = sPos[qi.sAt][0] + mx[i] * (cLog + 1);
						ny = sPos[qi.sAt][1] + my[i] * (cLog + 1);
						
						tmp = cLog;
						cLog = 0;
						if (valid(nx, ny) && qmp[nx][ny] >= 2)
							qi.cLogs[ qmp[nx][ny] - 2 ][i^2] = 0;
						if ( (it = stp.find(qi)) == stp.end() )
						{
							stp[qi] = qstp + 1;
							q.push(qi);
						}
						qi.hLogs = 0;
						cLog = tmp;
						if (valid(nx, ny) && qmp[nx][ny] >= 2)
							qi.cLogs[ qmp[nx][ny] - 2 ][i^2] = tmp;
					}
				}
			}
			
			// Put down
			if (qi.hLogs > 0)
			{
				minD[0] = minD[1] = minD[2] = minD[3] = INF;
				for (i = 0; i < ss; i++)
				{
					if (i == qi.sAt) continue;
					int &sx = sPos[i][0];
					int &sy = sPos[i][1];
					if (cx == sx || cy == sy)
					{
						dir = detDir(cx, cy, sx, sy);
						if ( (d = dist(cx, cy, sx, sy)) < minD[dir] )
						{
							minD[dir] = d;
							minS[dir] = i;
						}
					}
				}
				for (j = 0; j < 4; j++)
				{
					if (minD[j] == INF) continue;
					i = minS[j];
					int &sx = sPos[i][0];
					int &sy = sPos[i][1];
					av = 1;
					for (nx = cx + mx[j], ny = cy + my[j];
						nx != sx, ny != sy;
						nx += mx[j], ny += my[j] )
							if (qmp[nx][ny] != 0)
							{
								av = 0;
								break;
							}
					if (!av) continue;
					int &cLog = qi.cLogs[qi.sAt][j];
					if (qi.hLogs == dist(cx, cy, sx, sy) - 1
						&& (cLog == 0)
					)
					{
						tmp = qi.hLogs;
						cLog = qi.hLogs;
						qi.cLogs[i][j^2] = qi.hLogs;
						qi.hLogs = 0;
						if ( (it = stp.find(qi)) == stp.end() )
						{
							stp[qi] = qstp + 1;
							q.push(qi);
						}
						cLog = 0;
						qi.cLogs[i][j^2] = 0;
						qi.hLogs = tmp;
					}
				}
			}
			q.pop();
		}
		if (q.empty())
			puts("0");
		else
			printf("%d\n", qstp);
	}
	return 0;
}
