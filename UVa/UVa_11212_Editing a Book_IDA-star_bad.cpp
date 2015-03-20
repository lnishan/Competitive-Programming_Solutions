#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 10;
int n, a[N] = {2, 4, 1, 5, 3, 6};

inline int eval()
{
	int i, ret = 0;
	ret += a[0] != 1;
	for (i = 1; i < n; i++)
		ret += (a[i-1] > a[i] || a[i] - a[i-1] > 1);
	ret += a[n-1] != n;
	return ret == 0 ? -1 : ret / 3;
}

inline bool good(const int &i, const int &j)
{
	if (i < 0) return a[j] == 1;
	if (j >= n) return a[i] == n;
	return a[i] + 1 == a[j];
}

void insert(const int &i1, const int &i2, int t[], const int &len, const int &pos) // insert before pos
{
	int i, j, rlen = i2 - i1 + 1;
	for (i = len-1; i >= pos; i--)
		t[i + rlen] = t[i];
	for (i = pos, j = i1; j <= i2; i++, j++)
		t[i] = a[j];
}

bool dfs(const int &D, const int &g)
{
	int h = eval(), f = g + h;
	if (h == -1) return true;
	if (f > D) return false;
	int i, j, k, l, m;
	bool ret;
	// printf("g = %d, ", g); for (i = 0; i < n; i++) printf("%d ", a[i]); puts("");
	int *b = new int[n];
	for (i = 0; i < n; i++) b[i] = a[i];
	int *t = new int[n], *tmp = new int[n];
	for (i = 0; i < n; i++) // i = starting position
		for (j = i; j < n; j++)
			if (!good(i-1, i) && !good(j, j+1))
			{
				for (k = 0; k < i; k++)
					t[k] = a[k];
				for (l = j+1; l < n; l++)
					t[k++] = a[l];
				for (l = 0; l <= k; l++)
				{
					if (l == i) continue;
					if (good(l-1, l)) continue;
					for (m = 0; m < k; m++) tmp[m] = t[m];
					
					insert(i, j, t, k, l);
					for (m = 0; m < n; m++) a[m] = t[m];
					ret = dfs(D, g + 1);
					if (ret) return true;
					for (m = 0; m < n; m++) a[m] = b[m];
					
					for (m = 0; m < k; m++) t[m] = tmp[m];
				}
			}
	return false;
}

int main()
{
	//freopen("debug.txt", "w", stdout);
	
	int i, d, cases = 0;
	bool ret;
	while (scanf("%d", &n) && n)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (d = 0; !dfs(d, 0); d++);
		printf("Case %d: %d\n", ++cases, d);
	}
	return 0;
}
