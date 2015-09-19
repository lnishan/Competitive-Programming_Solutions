#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 805;

struct edge
{
	int vi, vj, wt;
	bool operator < (const edge &rhs)const
	{
		return wt < rhs.wt;
	}
};

int match[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, j, n, m;
	edge tmp;
	priority_queue<edge> pq;
	cin >> n; m = n;
	for (i = 2; i <= (n << 1); i++)
		for (j = 1; j < i; j++)
		{
			cin >> tmp.wt;
			tmp.vi = j; tmp.vj = i;
			pq.push(tmp);
		}
	while (m)
	{
		tmp = pq.top(); pq.pop();
		if (!match[tmp.vi] && !match[tmp.vj])
		{
			match[tmp.vi] = tmp.vj;
			match[tmp.vj] = tmp.vi;
			--m;
		}
	}
	for (i = 1; i <= (n << 1); i++)
		cout << match[i] << " ";
	return 0;
}
