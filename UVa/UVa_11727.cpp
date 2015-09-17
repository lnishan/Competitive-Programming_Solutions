#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i, tt, a[3];
	cin >> tt;
	for (i = 1; i <= tt; i++)
	{
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << "Case " << i << ": " << a[1] << "\n";
	}
	return 0;
}
