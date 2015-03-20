#include <cstdio>
#define MAX 100005
#define OPPO(X) 100002 + X

using namespace std;

int f[MAX << 1];

int findF(int idx)
{
	if (f[idx] == idx) return idx;
	return f[idx] = findF(f[idx]);
}

void unionF(int idx1, int idx2)
{
	int f1 = findF(idx1), f2 = findF(idx2);
	if (f1 < f2)
		f[f2] = f1;
	else
		f[f1] = f2;
}

int main()
{
	int i, t, n, m, a, b;
	char cmd[3];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
		{
			f[i] = i;
			f[OPPO(i)] = OPPO(i);
		}
		while (m--)
		{
			scanf("%s %d %d", cmd, &a, &b);
			if (cmd[0] == 'D')
			{
				unionF(a, OPPO(b));
				unionF(OPPO(a), b);
			}
			else // A
			{
				if (findF(a) == findF(b))
					puts("In the same gang.");
				else if (findF(a) == findF(OPPO(b)) || findF(OPPO(a)) == findF(b))
					puts("In different gangs.");
				else
					puts("Not sure yet.");
			}
		}
	}
	return 0;
}
