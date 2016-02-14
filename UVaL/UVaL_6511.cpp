#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N = 200005;

int choi[N], stk[N], top;
char vst[N];

int main() {
    int i, j, tt, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        fill(vst+1, vst+1 + n, 0);
        int ans = n;
        for (i = 1; i <= n; i++) scanf("%d", &choi[i]);
        for (i = 1; i <= n; i++)
            if (vst[i] == 0) {
                top = 0;
                int ci = i;
                while (vst[ci] == 0) {
                    vst[ci] = 1;
                    stk[++top] = ci;
                    ci = choi[ci];
                }
                if (vst[ci] == 1) {
                    while (stk[top] != ci) {
                        vst[stk[top]] = 2;
                        --ans;
                        --top;
                    }
                    --ans;
                }
                while (top) {
                    vst[stk[top]] = 2;
                    --top;
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
