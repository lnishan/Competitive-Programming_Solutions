#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pr;

const int N = 500005;
const int SQ = 712; // sqrt(N) + 5;

struct node
{
	ll add;
	int len;
	pr data[SQ];
//	node(): add(0) {}
} s[SQ << 1];

int n, l, u;
int a[N];

bool cmp(pr a, pr b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
		return a.second < b.second;
}
void build()
{
	int i, j;
	l = sqrt(n);
	u = (n - 1) / l;
	for (i = 0; i <= u; i++)
	{
		for (j = 0; j < l && i * l + j < n; j++)
		{
			s[i].data[j].first = a[i * l + j];
			s[i].data[j].second = j;
		}
		sort(s[i].data, s[i].data + j, cmp);
		s[i].add = 0; // optional
		s[i].len = j;
	}
}

class cmp2
{
public:
	bool operator ()(const pr &a, const ll &b)const
	{
		if (a.first == b)
			return false;
		else
			return a.first < b;
	}
	bool operator ()(const ll &a, const pr &b)const
	{
		if (a == b.first)
			return false;
		else
			return a < b.first;
	}
};
int query(ll y)
{
	int i, j, mn = 1e9, mx = -1;
	for (i = 0; i <= u; i++)
	{
		j = lower_bound(s[i].data, s[i].data + s[i].len, y - s[i].add, cmp2()) - (&s[i].data[0]);
		if (j < s[i].len && s[i].data[j].first == y - s[i].add)
			mn = min(mn, i * l + s[i].data[j].second), mx = max(mx, i * l + s[i].data[j].second);
		j = upper_bound(s[i].data, s[i].data + s[i].len, y - s[i].add, cmp2()) - (&s[i].data[0]);
		if (j > 0 && s[i].data[j - 1].first == y - s[i].add)
			mx = max(mx, i * l + s[i].data[j - 1].second);
	}
	return mx == -1 ? -1 : mx - mn;
}

void update_part(int i, int l, int r, ll x)
{
	int j;
	for (j = 0; j < s[i].len; j++)
		if (l <= s[i].data[j].second && s[i].data[j].second <= r)
			s[i].data[j].first += x;
	sort(s[i].data, s[i].data + s[i].len);
}

void update(int l, int r, ll x)
{
	int i, st = l / (::l), ed = r / (::l);
	if (st == ed)
	{
		update_part(st, l - (::l) * st, r - (::l) * st, x);
		return ;
	}
	update_part(st, l - st * (::l), s[st].len - 1, x);
	update_part(ed, 0, r - ed * (::l), x);
	for (i = st + 1; i < ed; i++)
		s[i].add += x;
}

int main()
{
	int i, j, q;
	int cmd, l, r;
	ll x, y;
	scanf("%d%d", &n, &q);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build();
	for (i = 0; i < q; i++)
	{
		scanf("%d", &cmd);
		if (cmd == 1)
		{
			scanf("%d%d%I64d", &l, &r, &x);
			--l; --r;
			update(l, r, x);
		}
		else if (cmd == 2)
		{
			scanf("%I64d", &y);
			printf("%d\n", query(y));
		}
	}
//	for (i = 0; i <= (n - 1) / l; i++)
//		for (j = 0; j < l; j++)
//			printf("%d %d: %d %d\n", i, j, s[i].data[j].first, s[i].data[j].second);
	return 0;
}