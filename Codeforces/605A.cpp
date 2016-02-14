#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

int pos[N];

int main() {
    int i, n, ai, ans = 1, tmp = 1;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ai);
        pos[ai] = i;
    }
    for (i = 2; i <= n; i++) {
        if (pos[i] > pos[i - 1])
            ++tmp;
        else
            tmp = 1;
        ans = max(ans, tmp);
    }
    printf("%d\n", n - ans);
    return 0;
}
