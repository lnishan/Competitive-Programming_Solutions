#include <cstdio>
#include <cstring>
#define MAX 100005
#define MOD 1000000007

using namespace std;

int a[MAX];
char s[MAX];


int main()
{
	int i, j, len, ans;
	scanf("%d ", &len);
	for (i = 0; i <= len + 1; i++) a[i] = 0;
	ans = 0;
	
	gets(s);
	a[len]++; a[0]--; // + 2^len - 1
	for (i = 0; i < len; i++)
		if (s[i] == '7')
			a[len - i - 1]++;
	for (i = 0; i <= len; i++)
		if (a[i] < 0)
		{
			a[i+1] -= ((-a[i]) + 1) >> 1;
			a[i] = (-a[i]) & 1; // % 2
		}
		else if (a[i] > 1)
		{
			a[i+1] += a[i] >> 1;
			a[i] = a[i] & 1;
		}
	for (i = len + 1; i >= 0; i--)
		ans = ((ans << 1) + a[i]) % MOD;
	printf("%d\n", ans);
	return 0;
}
