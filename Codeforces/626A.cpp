#include <bits/stdc++.h>

using namespace std;

const int N = 222;

int dx[N], dy[N];

char s[N];
int ans;

int main() {
    int i, j, k, n;
    scanf("%d ", &n);
    gets(s);
    for (i = 1; i <= n; i++) {
        dx[i] = dx[i - 1];
        dy[i] = dy[i - 1];
        if (s[i - 1] == 'U')
            dx[i]--;
        else if (s[i - 1] == 'R')
            dy[i]++;
        else if (s[i - 1] == 'D')
            dx[i]++;
        else if (s[i - 1] == 'L')
            dy[i]--;
        for (j = 0; j < i; j++)
            if (dx[i] == dx[j] && dy[i] == dy[j])
                ans++;
    }
    printf("%d\n", ans);
    return 0;
}
