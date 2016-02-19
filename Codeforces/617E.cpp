#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 2;
const int M = 2.1e6;

struct range {
	int i, l, r;
static int sq;
	bool operator <(const range &rhs)const {
		int x1 = l / sq, x2 = rhs.l / sq;
		if (x1 != x2)
			return x1 < x2;
		else
			return (x1 & 1) ? (r < rhs.r) : (r > rhs.r);
	}
};
int range::sq = 1000;
vector<range> rng;

int a[N], k;
int pre[N];
ll ans = 0;
int cnt[M];
int l = 0, r = -1;
ll aans[N];

void add(int idx) {
	// printf("idx = %d, pre[idx] = %d, add = %d\n", idx, pre[idx], cnt[pre[idx] ^ k]);
	ans += cnt[pre[idx] ^ k];
	cnt[pre[idx]]++;
}

void rem(int idx) {
	cnt[pre[idx]]--;
	// printf("idx = %d, pre[idx] = %d, rem = %d\n", idx, pre[idx], cnt[pre[idx] ^ k]);
	ans -= cnt[pre[idx] ^ k];
}

int main() {
	int i, n, q;
	scanf("%d%d%d", &n, &q, &k);
	range::sq = sqrt(n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);
	pre[0] = 0;
	for (i = 1; i <= n; i++) pre[i] = pre[i - 1] ^ a[i];
	// for (i = 0; i <= n; i++) printf("%d ", pre[i]); puts("");
	rng.resize(q);
	for (i = 0; i < q; rng[i].i = i, i++) scanf("%d%d", &rng[i].l, &rng[i].r);
	sort(rng.begin(), rng.end());
	for (auto &ri: rng) {
		if (r < ri.r) {
			for (i = r + 1; i <= ri.r; i++) {
				add(i);
				++r;
			}
		} else if (r > ri.r) {
			for (i = r; i > ri.r; i--) {
				rem(i);
				--r;
			}
		}
		if (l < ri.l - 1) {
			for (i = l; i < ri.l - 1; i++) {
				rem(i);
				++l;
			}
		}
		else if (l > ri.l - 1) {
			for (i = l - 1; i >= ri.l - 1; i--) {
				add(i);
				--l;
			}
		}
		aans[ri.i] = ans;
	}
	for (i = 0; i < q; i++) printf("%I64d\n", aans[i]);
	return 0;
}
