#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 102;

int n;
struct state
{
	vector<char> d;
	bool operator <(const state &b)const 
	{
		int i;
		for (i = 0; i < d.size(); i++)
			if (d[i] ^ b.d[i])
				return b.d[i];
		return false;
	}
};

map<state, int> m;
char s[105];

int main()
{
	int i, j, n, ans = 0;
	scanf("%d", &n);
	state tmp; tmp.d.resize(n);
	for (i = 0; i < n; i++)
	{
		scanf(" %s", s);
		for (j = 0; j < n; j++)
			tmp.d[j] = s[j] - '0';
		auto it = m.find(tmp);
		if (it == m.end())
		{
			m[tmp] = 1;
			ans = max(ans, 1);
		}
		else
		{
			it->second++;
			ans = max(ans, it->second);
		}
	}
	printf("%d\n", ans);
	return 0;
}