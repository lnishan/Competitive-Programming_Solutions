/*
Source: 0
Sink: 45

Source to Jobs(Applications)
-> capacity = number of jobs
<- X

Jobs to Computers
-> capacity = 1
<- capacity = 0

Computers to Sink
-> capacity = 1
<- X
*/ 

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_V 50
#define MAX_J 30
#define MAX_C 10
#define SINK 45
#define JOB(X) X - 'A' + 1
#define COMP(X) MAX_J + X
#define INF 2147483647

using namespace std;

int r[MAX_V][MAX_V];
vector<int> g[MAX_V];

queue<int> q;
int lvl[MAX_V];
char vst[MAX_V];

int iter[MAX_V];

int match[MAX_V];
char added[MAX_V][MAX_V];

void addEdge(int s, int e, int c)
{
	r[s][e] += c;
	g[s].push_back(e);
}

void doFlow(int s, int e, int f)
{
	r[s][e] -= f;
	r[e][s] += f;
	if (s < e) // assign job to computer
		match[e] = s;
	//else if (s > e) // deassign computer
	//	match[s] = -1;
}

int bfs(const int &s, const int &e)
{
	int i, sz, qi;
	memset(lvl, -1, sizeof(lvl));
	memset(vst, 0, sizeof(vst));
	
	lvl[s] = 0;
	vst[s] = 1;
	q.push(s);
	while (!q.empty())
	{
		qi = q.front();
		sz = g[qi].size();
		for (i = 0; i < sz; i++)
		{
			int &qj = g[qi][i];
			if (r[qi][qj] > 0 && !vst[qj])
			{
				lvl[qj] = lvl[qi] + 1;
				vst[qj] = 1;
				q.push(qj);
			}
		}
		q.pop();
	}
	return lvl[e];
}

int dfs(int idx, int minF, const int &dest)
{
	if (idx == dest) return minF;
	int ret, sz = g[idx].size();
	for (int &i = iter[idx]; i < sz; i++)
	{
		int &idxJ = g[idx][i];
		if (r[idx][idxJ] > 0 && lvl[idx] < lvl[idxJ])
		{
			ret = dfs(idxJ, min(minF, r[idx][idxJ]), dest);
			if (ret > 0)
			{
				doFlow(idx, idxJ, ret);
				return ret;
			}
		}
	}
	return 0;
}

int maxFlow(const int &s, const int &e)
{
	int ret = 0, f;
	while (bfs(s, e) >= 0)
	{
		memset(iter, 0, sizeof(iter));
		while ( (f = dfs(s, INF, e)) > 0)
			ret += f;
	}
	return ret;
}

char s[50];
char sJob[20], sComp[20];

int main()
{
	bool inp;
	int i, l, idxJob, idxComp, totJob, ret;
	while (1)
	{
		inp = false;
		totJob = 0;
		for (i = 0; i < MAX_V; i++) g[i].clear();
		memset(match, -1, sizeof(match));
		memset(r, 0, sizeof(r));
		memset(added, 0, sizeof(added));
		while (gets(s) && strlen(s) > 0)
		{
			inp = true;
			sscanf(s, "%s %s", sJob, sComp);
			idxJob = JOB(sJob[0]);
			totJob += sJob[1]-'0';
			
			// connect source to jobs
			addEdge(0, idxJob, sJob[1]-'0');
			
			// connect jobs to computers
			l = strlen(sComp);
			for (i = 0; i < l && sComp[i] != ';'; i++)
			{
				idxComp = COMP(sComp[i]-'0');
				if (!added[idxJob][idxComp])
				{
					added[idxJob][idxComp] = 1;
					addEdge(idxJob, idxComp, 1);
					addEdge(idxComp, idxJob, 0);
				}
			}
		}
		if (!inp) break;
		
		// connect computers to sink
		for (i = 0; i < MAX_C; i++)
			addEdge(COMP(i), SINK, 1);
		
		// start
		ret = maxFlow(0, SINK);
		if (ret == totJob)
		{
			for (i = 0; i < MAX_C; i++)
				if (match[COMP(i)] == -1)
					putchar('_');
				else
					putchar(match[COMP(i)] + 'A' - 1);
			puts("");
		}
		else
			puts("!");
		
		scanf(" ");
	}
}

