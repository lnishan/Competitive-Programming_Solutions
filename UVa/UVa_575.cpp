#include <cstdio>
#include <cstring>

using namespace std;

inline int input()
{
	char c; int x, sum;
	for (c = getchar(); c < 48 || c > 57; c = getchar() ) ;
	for (x = c - 48, sum = x, c = getchar();
			c > 47 && c < 58;
			sum += c - 48, c = getchar() )
		x = (x << 1) + sum + c - 48;
	return x;
}

int main()
{
	int n;
	while ((n = input()) && n)
		printf("%d\n", n);
	return 0;
}