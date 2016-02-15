#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int v, e;
char g[N][N];
char ans[N];

int main() {
	int i, j, vi, vj;
	scanf("%d%d", &v, &e);
	for (i = 0; i < e; i++) {
		scanf("%d%d", &vi, &vj);
		g[vi][vj] = g[vj][vi] = 1;
	}
	if (e == v * (v - 1) / 2) {
		puts("Yes");
		for (i = 0; i < v; i++) putchar('a');
	} else {
		vector<int> v1, v2;
		char flag = 0;
		for (i = 1; i <= v && !flag; i++)
			for (j = i + 1; j <= v; j++)
				if (!g[i][j]) {
					flag = 1;
					break;
				}
		--i;
		for (j = 1; j <= v; j++)
			if (j != i && !g[i][j])
				v2.emplace_back(j);
		for (i = 1; i <= v; i++)
			if (i != v2[0] && !g[i][v2[0]])
				v1.emplace_back(i);
		char ok = 1;
		for (auto &vi: v1) {
			for (auto &vj: v2) {
				if (vi == vj) {
					ok = 0;
					break;
				}
				if (g[vi][vj]) {
					ok = 0;
					break;
				} else
					g[vi][vj] = g[vj][vi] = 1;
			}
			if (!ok) break;
		}
		if (ok) {
			for (i = 1; i <= v && ok; i++)
				for (j = i + 1; j <= v; j++)
					if (!g[i][j]) {
						ok = 0;
						break;
					}
		}
		if (ok) {
			puts("Yes");
			for (auto &vi: v1) ans[vi] = 'a';
			for (auto &vj: v2) ans[vj] = 'c';
			for (i = 1; i <= v; i++) if (!ans[i]) ans[i] = 'b';
			ans[v + 1] = '\0';
			printf("%s\n", &ans[1]);
		} else
			puts("No");
	}
	return 0;
}
