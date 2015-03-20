#include <cstdio>

using namespace std;

int main()
{
	int k, left, right, t, a, b;
	scanf("%d", &t);
	for (k = 1; k <= t; k++)
	{
		left = right = 0;
		scanf("%d%d", &a, &b);
		while ( !(a==1 && b==1) )
		{
			if (a > b) // left
			{
				left += a/b;
				a %= b;
				
				if (a == 0)
				{
					left--;
					a += b;
				}
			}
			else
			{
				right += b/a;
				b %= a;
				
				if (b == 0)
				{
					right--;
					b += a;
				}
			}
		}
		printf("Scenario #%d:\n", k);
		printf("%d %d\n", left, right);
		puts("");
	}
	return 0;
}
