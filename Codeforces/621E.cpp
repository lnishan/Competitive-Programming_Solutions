#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 102;
const ll MOD = 1e9 + 7;

struct mat {
	vector<vector<ll> > m; int sz;
	mat(int _sz = N) {
		sz = _sz;
		m.resize(_sz);
		for (int i = 0; i < _sz; i++) m[i].resize(_sz);
	}
	mat&& operator * (const mat &rhs)const {
		int i, j, k;
		mat *ret = new mat(sz); (*ret).sz = sz;
		for (i = 0; i < sz; i++)
			for (j = 0; j < sz; j++) {
				(*ret).m[i][j] = 0;
				for (k = 0; k < sz; k++)
					(*ret).m[i][j] = ((*ret).m[i][j] + m[i][k] * rhs.m[k][j]) % MOD;
			}
		return move(*ret);
	}
	mat&& operator + (const mat &rhs)const {
		int i, j;
		mat *ret = new mat(sz); (*ret).sz = sz;
		for (i = 0; i < sz; i++)
			for (j = 0; j < sz; j++)
				(*ret).m[i][j] = (m[i][j] + rhs.m[i][j]) % MOD;
		return move(*ret);
	}
	void print() {
		int i, j;
		for (i = 0; i < sz; puts(""), i++)
			for (j = 0; j < sz; j++)
				printf("%d ", m[i][j]);
	}
};

int a[50002];

int main() {
	int i, j, k;
	int n, b, m, x;
	scanf("%d%d%d%d", &n, &b, &m, &x);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	mat tmp; tmp.sz = x;
	for (k = 0; k < n; k++)
		for (j = 0; j < x; j++) {
			i = ((j * 10) + a[k]) % x;
			tmp.m[i][j]++;
		}
	// tmp.print();
	mat T(x);
	for (i = 0; i < x; i++) for (j = 0; j < x; j++) T.m[i][j] = i == j;
	while (b) {
		if (b & 1)
			T = T * tmp;
		b >>= 1;
		tmp = tmp * tmp;
	}
	printf("%I64d\n", T.m[m][0]);
	return 0;
}
