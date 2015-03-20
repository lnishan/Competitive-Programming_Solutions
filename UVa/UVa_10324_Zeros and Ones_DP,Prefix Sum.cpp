#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1000002

using namespace std;

char s[MAX];
int ps[MAX];

int main()
{
	int i, l, sum, q, a, b, cases = 0;
	while (gets(s))
	{
		printf("Case %d:\n", ++cases);
		l = strlen(s);
		ps[0] = s[0] - '0';
		for (i = 1; i < l; i++)
			ps[i] = ps[i-1] + s[i]-'0';
		scanf("%d", &q);
		while (q--)
		{
			scanf("%d%d", &a, &b);
			if (a > b)
				swap(a, b);
			if (a == 0)
				sum = ps[b];
			else
				sum = ps[b] - ps[a-1];
			puts( sum == 0 || sum == (b-a+1) ? "Yes" : "No" );
		}
        scanf(" ");
	}
	return 0;
}
