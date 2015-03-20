#include <cstdio>
#include <cstring>
#define MAX 10002

using namespace std;

char gen[MAX];

int d(int n)
{
	int sum = n;
	while (n > 0)
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int i, res;
	
	// init
	memset(gen, 0, sizeof(gen)); // all not-generable
	
	// start
	for (i = 1; i < MAX; i++)
	{
		res = d(i);
		if (res < MAX)
			gen[res] = 1;
	}
	
	// output
	for (i = 1; i <= 10000; i++)
		if (!gen[i])
			printf("%d\n", i);
	return 0;
}
