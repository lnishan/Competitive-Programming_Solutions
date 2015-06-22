#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long int LLU;
const int N = 100005;
const LLU MOD = 1000000007;

struct node 
{
	char ch;
	int cnt;
	bool operator < (const node &rhs)const
	{
		return cnt > rhs.cnt;
	}
} a[4];
int idx_ch[130];
char s[N];

LLU ipow(LLU x, const int &n)
{
	if (!n) return 1;
	LLU tmp = ipow(x, n >> 1);
	if (n & 1)
		return (((tmp * tmp) % MOD) * x) % MOD;
	else
		return (tmp * tmp) % MOD;
};

int main()
{
	int i, j, l;
	idx_ch['A'] = 0;
	idx_ch['C'] = 1;
	idx_ch['G'] = 2;
	idx_ch['T'] = 3;
	scanf("%d ", &l);
	gets(s);
	l = strlen(s);
	a[0].cnt = a[1].cnt = a[2].cnt = a[3].cnt = 0;
	for (i = 0; i < l; i++)
		a[ idx_ch[s[i]] ].cnt++;
	sort(a, a+4);
	for (i = 1; i < 4 && a[i].cnt == a[i-1].cnt; i++) ;
	printf("%I64u\n", ipow(i, l));
	return 0;
}
