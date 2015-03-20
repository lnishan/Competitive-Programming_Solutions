#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 72
#define H 302
#define W 32
#define INF 0x3fffffff

using namespace std;

struct book
{
	int h, w;
	bool operator < (const book &rhs)const
	{
		return h > rhs.h;
	}
} a[N];

int dp[N][W * N][W * N]; // minimum total height

inline int max3(const int &a, const int &b, const int &c)
{
	return max( max(a, b), c );
}

int main()
{
	int i, j, k, t, n, h, w, totw, ctotw, w1, w2, w3, ans;
	scanf("%d", &t);
	while (t--)
	{
		totw = 0;
		scanf("%d", &n);
		for (i = 0; i < n; totw += a[i].w, i++)
			scanf("%d%d", &a[i].h, &a[i].w);
		
		ans = INF;
		for (i = 0; i < n; i++)
			for (j = 0; j <= totw; j++)
				for (k = 0; k <= totw; k++)
					dp[i][j][k] = INF;
		
		sort(a, a+n);
		
		totw = 0;
		dp[0][0][0] = a[0].h;
		for (i = 1; i < n; i++)
		{
			totw += a[i].w; // note that totw = Total width - The width of the tallest book
			// enumerate the width of the bookshelves
			for (w2 = 0; w2 <= totw; w2++)
				for (w3 = 0; w2 + w3 <= totw; w3++)
				{
					int &cur = dp[i][w2][w3];
					
					// check the first shelf
					w1 = totw - w2 - w3;
					if (w1 >= a[i].w && dp[i-1][w2][w3] != INF) // can fill
						cur = min(cur, dp[i-1][w2][w3]);
					
					// check the second shelf
					if (w2 >= a[i].w)
					{
						int &prev = dp[i-1][w2 - a[i].w][w3];
						if (prev != INF)
						{
							if (w2 > a[i].w)
								cur = min(cur, prev);
							else // if (w2 >= a[i].w)
								cur = min(cur, prev + a[i].h);
						}
					}
					
					// check the third shelf
					if (w3 >= a[i].w)
					{
						int &prev = dp[i-1][w2][w3 - a[i].w];
						if (prev != INF)
						{
							if (w3 > a[i].w)
								cur = min(cur, prev);
							else // if (w2 >= a[i].w)
								cur = min(cur, prev + a[i].h);
						}
					}
				}
		}
		
		for (w2 = 1; w2 <= totw; w2++)
			for (w3 = 1; w2 + w3 <= totw; w3++)
				if (dp[n-1][w2][w3] != INF)
					ans = min(ans, max3(totw - w2 - w3 + a[0].w, w2, w3) * dp[n-1][w2][w3]);
		
		printf("%d\n", ans);
	}
	return 0;
}
