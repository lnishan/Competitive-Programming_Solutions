#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int W, H;

bool fit(int w1, int h1, int w2, int h2)
{
	if (w1 > W || w2 > W) return false;
	if (w1 + w2 <= W)
		return max(h1, h2) <= H;
	else
		return h1 + h2 <= H;
}

int main()
{
	int i;
	int a, b, c, d;
	char f = 0;
	scanf("%d%d", &W, &H);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int test[4][4] = {
		{a, b, c, d},
		{a, b, d, c},
		{b, a, c, d},
		{b, a, d, c}
	};
	for (i = 0; i < 4; i++)
		f = max(f, (char)fit(test[i][0], test[i][1], test[i][2], test[i][3]));
	puts(f ? "YES" : "NO");
	return 0;
}