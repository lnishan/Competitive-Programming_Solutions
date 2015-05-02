#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200002;

int a[N], cnt;
int b4[N];
int stk[N], top;
int idx[N], lis[N], it;

int main()
{
	int i, n;
	cnt = 0;
	it = 0;
	top = -1;
	while (scanf("%d", &a[cnt]) == 1)
	{
		if (it == 0 || a[cnt] > lis[it-1])
		{
			lis[it] = a[cnt];
			idx[it] = cnt;
			i = it >= 1 ? idx[it-1] : -1;
			it++;
		}
		else
		{
			i = upper_bound(lis, lis+it, a[cnt]) - (&lis[0]);
			lis[i] = a[cnt];
			idx[i] = cnt;
			i = i >= 1 ? idx[i-1] : -1;
		}
		b4[cnt] = i;
		
		++cnt;
	}
	
	i = idx[it-1];
	while (i != -1)
	{
		stk[++top] = a[i];
		i = b4[i];
	}
	
	printf("%d\n", it);
	puts("-");
	for (i = top; i >= 0; i--)
		printf("%d\n", stk[i]);
	return 0;
}
