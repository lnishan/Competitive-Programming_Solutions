#include <cstdio>
#include <cstring>
#define N 1002

using namespace std;

int prev[N], f[N];
int cnt[N], wt[N];
char vst[N];

int findF(int idx)
{
	if (f[idx] == idx) return idx;
	return f[idx] = findF(f[idx]);
}

void unionF(int idx1, int idx2) // idx1 <-- idx2
{
	int f1 = findF(idx1), f2 = findF(idx2);
	f[f2] = f1;
	wt[f1] += wt[f2];
	cnt[f1] += cnt[f2];
}

int main()
{
	int i, j, n, root, vi, vj, ans;
	int maxId;
	double tmpWt, maxWt;
	while (scanf("%d%d", &n, &root) == 2 && (n | root))
	{
		// init
		ans = 0;
		for (i = 1; i <= n; i++)
		{
			prev[i] = -1;
			f[i] = i;
			cnt[i] = 1;
			vst[i] = 0;
		}
		
		// input
		for (i = 1; i <= n; i++)
			scanf("%d", &wt[i]);
		for (i = 1; i < n; i++)
		{
			scanf("%d%d", &vi, &vj);
			prev[vj] = vi;
		}
		
		// start
		for (i = 1; i < n; i++)
		{
			maxWt = 0;
			for (j = 1; j <= n; j++)
				if (!vst[j] && j != root && (tmpWt = double(wt[j]) / cnt[j]) > maxWt)
				{
					maxWt = tmpWt;
					maxId = j;
				}
			ans += wt[maxId] * cnt[ findF(prev[maxId]) ];
			unionF(prev[maxId], maxId);
			vst[maxId] = 1;
		}
		ans += wt[root];
		printf("%d\n", ans);
	}
	return 0;
}
