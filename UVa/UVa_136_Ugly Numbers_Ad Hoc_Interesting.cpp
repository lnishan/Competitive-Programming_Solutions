/* Idea:
 * a1 a2 a3 ... an
 *  1  2  3     []
 * an = can be some number a1~an-1 * 2
 * use a pointer to record what's the current number that hasn't x2 yet
 * similarly, declare 2 other pointers for 3 and 5
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long int LLU;
LLU a[1520];

int main()
{
	int i, i2, i3, i5;
	LLU n2, n3, n5;
	a[1] = 1;
	i2 = i3 = i5 = 1;
	for (i = 2; i <= 1500; i++)
	{
		while ( (n2 = a[i2] * 2) && n2 <= a[i-1] ) i2++;
		while ( (n3 = a[i3] * 3) && n3 <= a[i-1] ) i3++;
		while ( (n5 = a[i5] * 5) && n5 <= a[i-1] ) i5++;
		if (n2 <= n3 && n2 <= n5)
		{
			a[i] = n2;
			i2++;
		}
		else if (n3 <= n2 && n3 <= n5)
		{
			a[i] = n3;
			i3++;
		}
		else if (n5 <= n2 && n5 <= n3)
		{
			a[i] = n5;
			i5++;
		}
	}
	printf("The 1500'th ugly number is %llu.\n", a[1500]);
	return 0;
}
