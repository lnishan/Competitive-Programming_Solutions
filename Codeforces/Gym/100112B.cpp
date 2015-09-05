#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 100005;

int a[N];
int b[N];
int pos[N];

int inv = 0;

int t[N];
void mer(int l, int r)
{
	if (l == r) return ;
	int i, i1, i2, m = (l + r) >> 1;
	mer(l, m);
	mer(m + 1, r);
	for (i = 0, i1 = l, i2 = m + 1; i1 <= m && i2 <= r; i++)
		if (a[i1] < a[i2])
		{
			t[i] = a[i1];
			i1++;
		}
		else
		{
			t[i] = a[i2];
			i2++;
			inv += m + 1 - i1;
		}
	for ( ; i1 <= m; i1++, i++) t[i] = a[i1];
	for ( ; i2 <= r; i2++, i++) t[i] = a[i2];
	for (i = l; i <= r; i++) a[i] = t[i - l];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, n, ci;
	cin >> n;
	for (i = 0; i < n; i++) cin >> b[i];
	for (i = 0; i < n; i++)
	{
		cin >> ci;
		pos[ci] = i;
	}
	for (i = 0; i < n; i++)
		a[i] = pos[b[i]];
	mer(0, n - 1);
	puts((inv & 1) ? "Impossible" : "Possible");
	return 0;
}
