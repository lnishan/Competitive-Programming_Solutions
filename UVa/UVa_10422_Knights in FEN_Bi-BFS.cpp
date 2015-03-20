#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int max_stp = 5;

struct state
{
	int no;
	int wpos;
	bool operator < (const state &rhs)const
	{
		if (no != rhs.no)
			return no < rhs.no;
		else
			return wpos < rhs.wpos;
	}
};
struct state_res
{
	char stp;
	char from;
};

map<state, state_res> m;
map<state, state_res>::iterator it;
queue<state> q[2];

int mx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int my[8] = {2, 1, -1, -2, -2, -1, 1, 2};

inline bool valid(const int &x, const int &y)
{
	return x >= 0 && x < 5
		&& y >= 0 && y < 5;
}

inline void swapBit(int &n, const int &i, const int &j)
{
	int b1 = 24 - i, b2 = 24 - j;
	int n1 = (n >> b1) & 1;
	int n2 = (n >> b2) & 1;
	// clear
	if (n1) n ^= 1 << b1;
	if (n2) n ^= 1 << b2;
	// set
	if (n1) n |= 1 << b2;
	if (n2) n |= 1 << b1;
}

int main()
{
	char s[10];
	state st, ed, tmp;
	state_res restmp;
	ed.no = 33000480; ed.wpos = 12;
	int i, j, k, t, stp[2], nx, ny, ans;
	char cur;
	scanf("%d ", &t);
	while (t--)
	{
		ans = -1;
		m.clear();
		while (!q[0].empty()) q[0].pop();
		while (!q[1].empty()) q[1].pop();
		st.no = 0;
		
		for (i = 0; i < 5; i++)
		{
			fgets(s, 10, stdin);
			for (j = 0; j < 5; j++)
				if (s[j] == '1')
					st.no = (st.no << 1) | 1;
				else
				{
					st.no <<= 1;
					if (s[j] == ' ')
						st.wpos = i * 5 + j;
				}
		}
		if (!(st < ed) && !(ed < st))
		{
			puts("Solvable in 0 move(s).");
			continue;
		}
		stp[0] = stp[1] = 0;
		restmp.stp = 0; restmp.from = 0; m[st] = restmp;
		restmp.stp = 0; restmp.from = 1; m[ed] = restmp;
		q[0].push(st);
		q[1].push(ed);
		while (q[0].size() | q[1].size())
		{
			if (q[0].size() == 0)
				cur = 1;
			else if (q[1].size() == 0)
				cur = 0;
			else {
				if (stp[0] <= stp[1]) cur = 0; else cur = 1;
			}
			state &qi = q[cur].front();
			for (i = 0; i < 8; i++)
			{
				nx = qi.wpos / 5 + mx[i];
				ny = qi.wpos % 5 + my[i];
				if (valid(nx, ny))
				{
					tmp = qi;
					tmp.wpos = nx * 5 + ny;
					swapBit(tmp.no, qi.wpos, tmp.wpos);
					it = m.find(tmp);
					if (it == m.end())
					{
						restmp.stp = stp[cur] + 1;
						restmp.from = cur;
						if (restmp.stp <= max_stp)
						{
							m[tmp] = restmp;
							q[cur].push(tmp);
						}
					}
					else
					{
						state_res &mi = it->second;
						if ( mi.from != cur ) // found ans
						{
							ans = stp[cur] + 1 + mi.stp;
							break;
						}
					}
				}
			}
			if (ans != -1) break;
			q[cur].pop();
			if (!q[cur].empty())
				stp[cur] = m[q[cur].front()].stp;
			//printf("%d %d\n", stp[0], stp[1]);
		}
		if (ans == -1 || ans > 10)
			puts("Unsolvable in less than 11 move(s).");
		else
			printf("Solvable in %d move(s).\n", ans);
	}
	return 0;
}
