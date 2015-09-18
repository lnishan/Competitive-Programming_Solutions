#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
ll a[N], f[N], b[N];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, n, k, m;
	ll mul = 1, ans = 0;
	cin >> n >> k >> m;
	while (k--) mul *= m;
	for (i = 1; i <= n; i++) cin >> a[i];
	for (i = 1; i <= n; i++) f[i] = f[i - 1] | a[i];
	for (i = n; i >= 1; i--) b[i] = b[i + 1] | a[i];
	for (i = 1; i <= n; i++)
		ans = max(ans, f[i - 1] | (a[i] * mul) | b[i + 1]);
	cout << ans;
	return 0;
}
