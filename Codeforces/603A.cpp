#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;

char s[N];

int main() {
    int i, n, p0, p1, n0, n1, ans = 1;
    scanf("%d ", &n);
    fgets(s, N, stdin);
    p0 = s[0] == '0';
    p1 = s[0] == '1';
    for (i = 1; i < n; i++) {
        n0 = p0;
        n1 = p1;
        if (s[i] == '0')
            n0 = max(n0, p1 + 1);
        else
            n1 = max(n1, p0 + 1);
        p0 = n0;
        p1 = n1;
        ans = max(ans, n0);
        ans = max(ans, n1);
    }
    int tmp = 0;
    for (i = 1; i < n; i++)
        if (s[i] == s[i - 1])
            tmp++;
    if (tmp > 2) tmp = 2;
    printf("%d\n", ans + tmp);
    return 0;
}
