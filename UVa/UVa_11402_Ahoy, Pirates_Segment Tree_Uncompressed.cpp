#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#define L(X) (X << 1)
#define R(X) ((X << 1) + 1)

using namespace std;

typedef unsigned int U;

const int N = 10250000;

struct node
{
	char all;
	char inv;
	int cnt;
	int get_cnt(int l, int r, int a_all, int a_inv)
	{
		a_inv ^= inv;
		if (a_all == -1 && all != -1) a_all = all ^ a_inv;
		if (a_all == -1)
			return a_inv ? r - l + 1 - cnt : cnt;
		else
			return all ^ a_inv ? r - l + 1 : 0;
	}
} t[N << 2];

char s[N];

int build(const int &idx, const int &l, const int &r)
{
	node &n = t[idx];
	n.all = -1;
	n.inv = 0;
	if (r == l)
	{
		n.cnt = s[l] == '1';
		return n.cnt;
	}
	int m = (l + r) >> 1;
	n.cnt = build(L(idx), l, m) + build(R(idx), m + 1, r);
	return n.cnt;
}

int query(const int &idx, const int &l, const int &r, const int &ql, const int &qr, char a_all, char a_inv)
{
	node &n = t[idx];
	a_inv ^= n.inv;
	if (a_all == -1 && n.all != -1) a_all = n.all ^ a_inv;
	if (a_all != -1)
		return a_all ? qr - ql + 1 : 0;
	if (l == ql && r == qr)
		return a_inv ? r - l + 1 - n.cnt : n.cnt;
	int m = (l + r) >> 1, ret = 0;
	if (ql <= m)
		ret += query( L(idx), l, m, ql, min(qr, m), a_all, a_inv);
	if (qr > m)
		ret += query( R(idx), m + 1, r, max(m + 1, ql), qr, a_all, a_inv);
//	printf("[%d, %d] [%d, %d] %d\n", l, r, ql, qr, ret);
	return ret;
}

int update_set(const int &idx, const int &l, const int &r, const int &ql, const int &qr, char a_all, char a_inv,  char clr)
{
	node &n = t[idx];
	a_inv ^= n.inv;
	if (a_all == -1 && n.all != -1) a_all = n.all ^ a_inv;
	if (l == ql && r == qr)
	{
		n.all = clr ^ a_inv;
		return clr ? r - l + 1 : 0;
	}

	int idx_l = L(idx), idx_r = R(idx);
	if (a_all != -1)
	{
 		t[idx_l].all = a_all ^ (a_inv ^ t[idx_l].inv);
		t[idx_r].all = a_all ^ (a_inv ^ t[idx_r].inv);
	}
	int m = (l + r) >> 1, ret = 0;
	
	if (ql <= m)
		ret += update_set(idx_l, l, m, ql, min(qr, m), a_all, a_inv, clr);
	else
		ret += t[idx_l].get_cnt(l, m, a_all, a_inv);
	
	if (qr > m)
		ret += update_set(idx_r, m + 1, r, max(m + 1, ql), qr, a_all, a_inv, clr);
	else
		ret += t[idx_r].get_cnt(m + 1, r, a_all, a_inv);
	
	n.all = -1;
	n.cnt = a_inv ? r - l + 1 - ret : ret;
	return ret;
}

int update_inv(const int &idx, const int &l, const int &r, const int &ql, const int &qr, int a_all, char a_inv)
{
	node &n = t[idx];
	a_inv ^= n.inv;
	if (a_all == -1 && n.all != -1) a_all = n.all ^ a_inv;
	if (l == ql && r == qr)
	{
		n.inv ^= 1;
		a_inv ^= 1;
		if (a_all == -1)
			return a_inv ? r - l + 1 - n.cnt : n.cnt;
		else
			return a_all ^ 1 ? r - l + 1 : 0;
	}
	int idx_l = L(idx), idx_r = R(idx);
	if (a_all != -1)
	{
		t[idx_l].all = a_all ^ (a_inv ^ t[idx_l].inv);
		t[idx_r].all = a_all ^ (a_inv ^ t[idx_r].inv);
	}
	int m = (l + r) >> 1, ret = 0;
	if (ql <= m)
		ret += update_inv(idx_l, l, m, ql, min(qr, m), a_all, a_inv);
	else
		ret += t[idx_l].get_cnt(l, m, a_all, a_inv);
	
	if (qr > m)
		ret += update_inv(idx_r, m + 1, r, max(m + 1, ql), qr, a_all, a_inv);
	else
		ret += t[idx_r].get_cnt(m + 1, r, a_all, a_inv);
	
	n.all = -1;
	n.cnt = a_inv ? r - l + 1 - ret : ret;
	return ret;
}

// Barbary = 0, Buccaneer = 1

int main()
{
	int i, j, tt, p, r, q, n, qc, l;
	char ts[55];
	char cmd[5];
	scanf("%d", &tt);
	for (int c = 1; c <= tt; c++)
	{
		printf("Case %d:\n", c);
		n = 0;
		qc = 0;
		s[0] = '\0';
		cin >> p;
		while (p--)
		{
			scanf("%d ", &r);
			gets(ts);
			l = strlen(ts);
			while (r--)
				for (i = 0; i < l; i++)
					s[n++] = ts[i];
		}
//		n = strlen(s);
		build(1, 0, n - 1);
//		print_tree(n);
		scanf("%d", &q);
		while (q--)
		{
			scanf(" %s %d %d", cmd, &i, &j);
			if (cmd[0] == 'F') // turn to 1
				update_set(1, 0, n - 1, i, j, -1, 0, 1);
			else if (cmd[0] == 'E')
				update_set(1, 0, n - 1, i, j, -1, 0, 0);
			else if (cmd[0] == 'I')
				update_inv(1, 0, n - 1, i, j, -1, 0);
			else // S
				printf("Q%d: %d\n", ++qc, query(1, 0, n - 1, i, j, -1, 0));
		}
	}
	return 0;
}
