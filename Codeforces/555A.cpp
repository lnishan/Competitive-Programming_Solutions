#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[100005];

int main()
{
	int i, j, n, cc, cn;
	int ans = 0;
	scanf("%d%d", &n, &cc);
	while (cc--)
	{
		scanf("%d", &cn);
		for (i = 0; i < cn; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < cn; i++)
		{
			for (j = i + 1; j < cn && a[j] == a[j - 1] + 1; j++) ;
			if (a[i] != 1)
				ans += 2 * (j - i) - 1;
			++ans;
			i = j - 1;
		}
		--ans;
	}
	printf("%d\n", ans);
	return 0;
}