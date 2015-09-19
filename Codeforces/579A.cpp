#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, ans = 0;
	cin >> n;
	while (n)
	{
		ans += (n & 1);
		n >>= 1;
	}
	cout << ans;
	return 0;
}
