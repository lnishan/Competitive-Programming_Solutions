#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll inf = 1e18;

ll s[N << 2];

struct cake {
	int id;
	ll vol; // excluding PI
} a[N];

void build(int idx, int l, int r) {
	if (r == l) { s[idx] = 0; return ; }
	int m = (l + r) >> 1;
	build(idx << 1, l, m);
	build(idx<<1|1, m + 1, r);
	s[idx] = 0;
}

void upd(int idx, int l, int r, const int &qi, const ll &val){
	if (r == l) { s[idx] = val; return ; }
	int m = (l + r) >> 1;
	if (qi <= m)
		upd(idx << 1, l, m, qi, val);
	else
		upd(idx<<1|1, m + 1, r, qi, val);
	s[idx] = max(s[idx << 1], s[idx<<1|1]);
	return ;
}

ll qry(int idx, int l, int r, int ql, int qr) {
	if (r < ql || l > qr) return 0;
	if (ql <= l && r <= qr) return s[idx];
	int m = (l + r) >> 1;
	return max(qry(idx << 1, l, m, ql, qr), qry(idx<<1|1, m + 1, r, ql, qr));
}

int main() {
	int i, j, k, n, r, h;
	scanf("%d", &n);
	build(1, 0, n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &r, &h);
		a[i].id = i;
		a[i].vol = (ll)r * r * h;
	}
	ll ans = 0;
	sort(a+1, a+1 + n, [](cake a, cake b) { return a.vol < b.vol; });
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n && a[j].vol == a[i].vol; j++) ;
		vector<ll> ansk; ansk.reserve(j - i);
		for (k = i; k < j; k++) {
			ansk.push_back(qry(1, 0, n, 0, a[k].id - 1) + a[k].vol);
			ans = max(ans, ansk.back());
		}
		for (k = i; k < j; k++)
			upd(1, 0, n, a[k].id, ansk[k - i]);
		i = j - 1;
	}
	printf("%.17f\n", (double)(ans * acos((long double)-1)));
	return 0;
}
