#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 12;

int n;
int a[N][N], t[N][N];

int mx[4] = {1, -1, 0, 0}, my[4] = {0, 0, 1, -1};
inline bool valid(const int &i, const int &j)
{
	return i >= 0 && i < n && j >= 0 && j < n;
}
void press(int i, int j)
{
	int k;
	t[i][j] ^= 1;
	for (k = 0; k < 4; k++)
		if (valid(i + mx[k], j + my[k]))
			t[i + mx[k]][j + my[k]] ^= 1;
}

int proc()
{
	int i, j, ret = 0;
	for (i = 1; i < n; i++)
		for (j = 0; j < n; j++)
			if (!t[i - 1][j])
				press(i, j), ret++;
	for (j = 0; j < n; j++)
		if (!t[n - 1][j])
			return - 1;
	return ret;
}

char nm[1002], s[N + 2];
int main()
{
	int i, j, k, stp, ret, ans;
	n = 10;
	while (scanf(" %s", nm) == 1 && strcmp(nm, "end") != 0)
	{
		ans = 1e9;
		scanf(" ");
		for (i = 0; i < n; i++)
		{
			gets(s);
			for (j = 0; j < n; j++)
				a[i][j] = s[j] == '#';
		}
		for (k = 0; k < (1 << n); k++)
		{
			for (i = 0; i < n; i++) for (j = 0; j < n; j++) t[i][j] = a[i][j];
			stp = 0;
			for (i = 0; i < n; i++)
				if (k & (1 << i))
					press(0, i), stp++;
			ret = proc();
			if (ret != -1)
				ans = min(ans, stp + ret);
		}
		if (ans > 100)
			printf("%s %d\n", nm, -1);
		else
			printf("%s %d\n", nm, ans);
	}
	return 0;
}