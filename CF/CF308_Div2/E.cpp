#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

char s[5005];
ll f[3000], b[3000], p[3000];
ll ft[3000], bt[3000];
ll sn[3000]; int sn_top;
char so[3000]; int so_top;

int main()
{
	int i, j, n, l;
	ll t, m;
	ll tmp, tmp_f, tmp_b, ans;
	gets(s); l = strlen(s);
	ans = s[0] - '0';
	n = (l - 1) >> 1;
	
	f[0] = s[0] - '0';
	ft[0] = f[0];
	sn_top = so_top = -1;
	for (i = 1, t = f[0]; i <= n; i++)
	{
		char &op = s[i * 2 - 1];
		m = s[i * 2] - '0';
		if (op == '+')
		{
			while (so_top >= 0 && so[so_top] == '*')
			{
				sn[sn_top - 1] *= sn[sn_top];
				--sn_top;
				--so_top;
			}
			sn[++sn_top] = m;
			so[++so_top] = op;
			f[i] = f[i - 1] + m;
			t = m;
		}
		else
		{
			sn[++sn_top] = m;
			so[++so_top] = op;
			f[i] = f[i - 1] - t + t * m;
			t *= m;
		}
		ft[i] = t;
	}
//	for (i = 0; i <= n; i++)
//		printf("%d %I64d\n", i, f[i]);
	b[n] = s[n * 2] - '0';
	bt[n] = b[n];
	sn_top = so_top = -1;
	for (i = n - 1, t = b[n]; i >= 0; i--)
	{
		char &op = s[i * 2 + 1];
		m = s[i * 2] - '0';
		if (op == '+')
		{
			while (so_top >= 0 && so[so_top] == '*')
			{
				sn[sn_top - 1] *= sn[sn_top];
				--sn_top;
				--so_top;
			}
			sn[++sn_top] = m;
			so[++so_top] = op;
			b[i] = b[i + 1] + m;
			t = m;
		}
		else
		{
			sn[++sn_top] = m;
			so[++so_top] = op;
			b[i] = b[i + 1] - t + t * m;
			t *= m;
		}
		bt[i] = t;
	}
//	for (i = n; i >= 0; i--)
//		printf("%d %I64d\n", i, b[i]);
	for (i = 0; i < n; i++)
	{
		p[i] = s[i * 2] - '0';
		sn_top = so_top = -1;
		for (j = i + 1, t = p[i]; j <= n; j++)
		{
			char &op = s[j * 2 - 1];
			m = s[j * 2] - '0';
			if (op == '+')
			{
				while (so_top >= 0 && so[so_top] == '*')
				{
					sn[sn_top - 1] *= sn[sn_top];
					--sn_top;
					--so_top;
				}
				sn[++sn_top] = m;
				so[++so_top] = op;
				p[j] = p[j - 1] + m;
				t = m;
			}
			else
			{
				sn[++sn_top] = m;
				so[++so_top] = op;
				p[j] = p[j - 1] - t + t * m;
				t *= m;
			}
			tmp_f = i ? f[i - 1] : 0;
			tmp_b = j + 1 <= n ? b[j + 1] : 0;
			tmp = p[j];
			if (i && s[i * 2 - 1] == '*')
				tmp *= ft[i - 1], tmp_f -= ft[i - 1];
			if (j + 1 <= n && s[j * 2 + 1] == '*')
				tmp *= bt[j + 1], tmp_b -= bt[j + 1];
			tmp += tmp_f + tmp_b;
			ans = max(ans, tmp);
		}
	}
	printf("%I64d\n", ans);
	return 0;
}