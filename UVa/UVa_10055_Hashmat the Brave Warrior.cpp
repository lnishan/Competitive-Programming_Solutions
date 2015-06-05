#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main()
{
	ios::sync_with_stdio(false);
	LL a, b;
	while (cin >> a >> b)
		cout << ((b > a) ? b - a : a - b) << endl;
	return 0;

}