#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int n;
int a[100005];
int bf[100005], nx[100005];

void print_ans()
{
	int i, j;
	puts("YES");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < bf[i]; j++) putchar('(');
		putchar(a[i] + '0');
		for (j = 0; j < nx[i]; j++) putchar(')');
		if (i < n - 1) printf("->");
	}
}

int main()
{
	int i, j;
	scanf("%d", &n);
	fill(bf, bf + n, 0);
	fill(nx, nx + n, 0);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 1 && a[0] == 0)
		printf("YES\n0");
	else
	{
		if (a[n - 1] == 1)
			puts("NO");
		else
		{
			if (a[n - 2] == 1)
			{
				for (i = 1; i < n - 1; i++)
				{
					bf[0]++;
					nx[i]++;
				}
				bf[0]++;
				nx[n - 1]++;
				
				print_ans();
			}
			else
			{
				
				for (i = n - 3; i >= 0; i--)
					if (a[i] == 0) break;
				if (i < 0)
					puts("NO");
				else
				{
					for (j = n - 3; j >= i; j--)
					{
						nx[n - 2]++;
						bf[j]++;
					}
					for (j = 1; j < i; j++)
					{
						bf[0]++;
						nx[j]++;
					}
					bf[0]++;
					nx[n - 2]++;
					bf[0]++;
					nx[n - 1]++;
					
					print_ans();
				}
			}
			
		}
	}
	return 0;
}