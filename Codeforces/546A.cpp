#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int k, n, w;
	cin >> k >> n >> w;
	int ans = k * w * (w + 1) / 2 - n;
	cout << (ans < 0 ? 0 : ans) << endl;
	return 0;

}