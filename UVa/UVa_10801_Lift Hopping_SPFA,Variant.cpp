#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
#include <cctype>
#define INF 0x3fffffff

using namespace std;

const int E = 5;
const int F = 102;

int dp[E][F];
char inQ[E][F];
queue<pair<int, int> > q;
int et[E];
vector<int> ef[E];
char valid[E][F];
char *ptr, s[1002];

int main()
{
	int i, j, n, k, efi, nt, ans;
	while (scanf("%d%d", &n, &k) == 2)
	{
		ans = INF;
		while (!q.empty()) q.pop();
		for (i = 0; i < n; i++)
		{
			ef[i].clear();
			for (j = 0; j < F; j++)
			{
				dp[i][j] = INF;
				inQ[i][j] = 0;
				valid[i][j] = 0;
			}
		}
		for (i = 0; i < n; i++)
			scanf("%d", &et[i]);
		scanf(" ");
		for (i = 0; i < n; i++)
		{
			gets(s);
			ptr = strtok(s, " ");
			while (ptr != NULL)
			{
				efi = atoi(ptr);
				ef[i].push_back(efi);
				valid[i][efi] = 1;
				ptr = strtok(NULL, " ");
			}
		}
		for (i = 0; i < n; i++)
			if (valid[i][0])
			{
				dp[i][0] = 0;
				inQ[i][0] = 1;
				q.push(make_pair(i, 0));
			}
		while (!q.empty())
		{
			pair<int, int> &qi = q.front();
			
			// traveling on the same elevator
			int &qe = qi.first;
			int &qf = qi.second;
			const int &sz = ef[qe].size();
			for (i = 0; i < sz; i++)
			{
				int &f = ef[qe][i];
				if (f == qf) continue;
				nt = dp[qe][qf] + abs(f - qf) * et[qe];
				if (nt < dp[qe][f])
				{
					dp[qe][f] = nt;
					// printf("Same elevator [%d][%d] = %d\n", qe, f, nt);
					if (!inQ[qe][f])
					{
						inQ[qe][f] = 1;
						q.push(make_pair(qe, f));
					}
				}
			}
			
			// different elevator
			nt = dp[qe][qf] + 60;
			for (i = 0; i < n; i++)
			{
				if (i == qe) continue;
				if (valid[i][qf] && nt < dp[i][qf]) // ith elevator stops at this floor ?
				{
					dp[i][qf] = nt;
					// printf("Change elevator [%d][%d] = %d\n", i, qf, nt);
					if (!inQ[i][qf])
					{
						inQ[i][qf] = 1;
						q.push(make_pair(i, qf));
					}
				}
			}
			
			inQ[qe][qf] = 0;
			q.pop();
		}
		for (i = 0; i < n; i++)
			if (valid[i][k])
				ans = min(ans, dp[i][k]);
		if (ans == INF)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", ans);
	}
	return 0;
}
