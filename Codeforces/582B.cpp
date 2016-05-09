#include <bits/stdc++.h>

using namespace std;

const int N = 102;
const int MOD = 1e9 + 7;

struct mat {
	int m[N][N];
	
	void print(int n) const {
		int i, j;
		for (i = 0; i < n; i++, puts(""))
			for (j = 0; j < n; j++)
				printf("%d ", m[i][j]);
		puts("");
	}
	mat operator + (const mat &rhs)const {
		mat ret;
		int i, j;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				ret.m[i][j] = m[i][j] + rhs.m[i][j];
		return ret;
	}
	mat operator * (const mat &rhs)const {
		int i, j, k;
		mat ret;
		// puts("LHS"); print(31);
		// puts("RHS"); rhs.print(31);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				ret.m[i][j] = 0;
				for (k = 0; k < N; k++)
					ret.m[i][j] = max(ret.m[i][j], m[i][k] + rhs.m[k][j]);
			}
		// puts("RET"); ret.print(31);
		return ret;
	}
};

int main() {
	int i, jj, j, k;
	int n, t, a[N];
	mat T;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) T.m[i][j] = 0;
	scanf("%d%d", &n, &t);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		vector<int> lis;
		lis.push_back(a[i]);
		T.m[i][i] = 1;
		for (jj = i + 1; jj < n + i; jj++) {
			j = jj >= n ? jj - n : jj;
			if (a[j] < a[i]) { T.m[j][i] = 0; continue; }
			if (a[j] >= lis.back()) {
				T.m[j][i] = lis.size();
				lis.push_back(a[j]);
			} else {
				int idx = upper_bound(lis.begin(), lis.end(), a[j]) - lis.begin();
				T.m[j][i] = idx;
				lis[idx] = a[j];
			}
		}
		// printf("i = %d, lis.size() = %d\n", i, (int)lis.size());
	}
	T.print(n);
	mat A;
	for (i = 0; i < N; i++) for (j = 0; j < N; j++) A.m[i][j] = 0;
	while (t) {
		// puts("T"); T.print(n);
		if (t & 1)
			A = T * A;
		t >>= 1;
		T = T * T;
		// puts("A"); A.print(n);
	}
	A.print(n);
	int ans = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			ans = max(ans, A.m[i][j]);
	printf("%d\n", ans);
	return 0;
}
