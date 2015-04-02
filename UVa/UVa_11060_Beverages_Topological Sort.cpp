/* Lexicographically smallest topological order
Idea: Repeatedly finding the smallest vertex with 0 in-degree */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

const int V = 102;

int v, e;
map<string, int> id;
map<string, int>::iterator it;
string nm[V];
vector<int> g[V];
char used[V];
int indeg[V];
struct node
{
	int idx;
	int indeg;
	bool operator < (const node &rhs)const
	{
		if (indeg != rhs.indeg)
			return indeg > rhs.indeg;
		else
			return idx > rhs.idx;
	}
};
priority_queue<node> pq;
vector<int> ans;

inline int get_id(string &n)
{
	it = id.find(n);
	return it->second;
}

int main()
{
	int i, j, c = 0;
	string v1, v2;
	int i1, i2;
	while (scanf("%d", &v) == 1)
	{
		ans.clear();
		id.clear();
		memset(used, 0, sizeof(used));
		memset(indeg, 0, sizeof(indeg));
		for (i = 0; i < v; i++) g[i].clear();
		while (!pq.empty()) pq.pop();
		
		for (i = 0; i < v; i++)
		{
			cin >> nm[i];
			id[nm[i]] = i;
		}
		scanf("%d", &e);
		for (i = 0; i < e; i++)
		{
			cin >> v1 >> v2;
			i1 = get_id(v1);
			i2 = get_id(v2);
			g[i1].push_back(i2);
			indeg[i2]++;
		}
		for (i = 0; i < v; i++)
			pq.push( (node){i, indeg[i]} );
		/*
		while (!pq.empty())
		{
			printf("%d %d\n", pq.top().idx, pq.top().indeg);
			pq.pop();
		}*/
		while (!pq.empty())
		{
			const node &qi = pq.top();
			int vi = qi.idx;
			int in = qi.indeg;
			pq.pop();
			if (!used[vi] && in == 0)
			{
				used[vi] = 1;
				ans.push_back(vi);
				const int &sz = g[vi].size();
				for (i = 0; i < sz; i++)
				{
					int &vj = g[vi][i];
					indeg[vj]--;
					pq.push( (node){vj, indeg[vj]} );
				}
			}
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", ++c);
		for (i = 0; i < ans.size(); i++)
			cout << " " << nm[ans[i]];
		printf(".\n\n");
	}
	return 0;
}
