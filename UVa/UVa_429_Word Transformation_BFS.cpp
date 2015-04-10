#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3fffffff

using namespace std;

const int V = 202;

int v;
string nm[V];
map<string, int> id;
map<string, int>::iterator it;
vector<int> g[V];
queue<int> q;
int d[V];

int main()
{
	int i, j, k, diff, t;
	string s, s1, s2;
	int i1, i2;
	scanf("%d", &t);
	while (t--)
	{
		v = 0;
		
		id.clear();
		scanf(" ");
		while (getline(cin, nm[v]) && nm[v] != "*")
			id[nm[v]] = v++;
		for (i = 0; i < v; i++) g[i].clear();;
		
		for (i = 0; i < v; i++)
			for (j = 0; j < v; j++)
			{
				if (i == j) continue;
				if (nm[i].length() != nm[j].length()) continue;
				for (diff = 0, k = 0; k < nm[i].length() && diff <= 1; k++)
					diff += (nm[i][k] != nm[j][k]);
				if (diff <= 1)
					g[i].push_back(j);
			}
		while (getline(cin, s) && !s.empty())
		{
			fill(d, d+v, INF);
			while (!q.empty()) q.pop();
			
			stringstream ss(s);
			ss >> s1 >> s2;
			// cout << s1 << " " << s2 << endl;
			i1 = id[s1];
			i2 = id[s2];
			
			d[i1] = 0;
			q.push(i1);
			while (!q.empty())
			{
				int &qi = q.front();
				if (qi == i2) break;
				const int &sz = g[qi].size();
				for (i = 0; i < sz; i++)
				{
					int &qj = g[qi][i];
					if (d[qj] == INF)
					{
						d[qj] = d[qi] + 1;
						q.push(qj);
					}
				}
				q.pop();
			}
			cout << s1 << " " << s2 << " " << d[i2] << endl;
		}
		
		if (t) puts("");
	}
	return 0;
}
