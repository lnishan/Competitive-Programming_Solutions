#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 3005;
int cnt[N << 1];

int main()
{
	int i, j, n, ai, ans = 0;
	memset(cnt, 0, sizeof(cnt));
	cin >> n;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ai);
		cnt[ai]++;
	}
	for (i = 0; i < (N << 1); i++)
		if (cnt[i] > 1)
		{
			ans += cnt[i] - 1;
			cnt[i+1] += cnt[i] - 1;
		}
	cout << ans << endl;
	return 0;

}
