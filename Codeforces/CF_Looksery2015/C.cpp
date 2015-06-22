#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const char *S = "Stannis";
const char *D = "Daenerys";

int main()
{
	int i;
	int c[2] = {0, 0};
	int n, k, ai, ns, nd;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &ai);
		c[ai & 1]++;
	}
	if (n == k)
	{
		puts(c[1] & 1 ? S : D);
	}
	else if (c[0] == 0)
	{
		puts((c[1] - (n - k)) & 1 ? S : D);
	}
	else if (c[1] == 0)
	{
		puts(D);
	}
	else
	{
		nd = (n - k) >> 1;
		ns = n - k - nd;
		if ( (n - k) & 1 )
		{
			if (nd < c[1])
			{
				if (nd >= c[0] && ((c[1] - (nd - c[0]) - ns) & 1) == 0)
					puts(D);
				else
					puts(S);
			}
			else
				puts(D);
		}
		else
		{
			if (ns < c[0])
				puts(D);
			else
			{
				if (ns >= c[0] && ((c[1] - (ns - c[0]) - nd) & 1))
					puts(S);
				else
					puts(D);
			}
		}
	}
	return 0;
}