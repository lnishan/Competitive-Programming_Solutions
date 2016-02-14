#include <bits/stdc++.h>

using namespace std;

struct item {
    char color;
    int cnt;
} a[3];

const int N = 222;

char s[N];

int main() {
    a[0].color = 'R';
    a[1].color = 'G';
    a[2].color = 'B';
    int i, j, n;
    for (i = 0; i < 3; i++) a[i].cnt = 0;
    scanf("%d ", &n);
    gets(s);
    for (i = 0; i < n; i++)
        if (s[i] == 'R')
            a[0].cnt++;
        else if (s[i] == 'G')
            a[1].cnt++;
        else if (s[i] == 'B')
            a[2].cnt++;
    sort(a, a + 3, [](item a, item b){ return a.cnt < b.cnt; });
    if (a[0].cnt == 0 && a[1].cnt == 0) {
        putchar(a[2].color);
        puts("");
    } else if (a[0].cnt == 0) {
        if (a[1].cnt >= 2 && a[2].cnt >= 2) {
            puts("BGR");
        } else if (a[1].cnt == 1 && a[2].cnt == 1) {
            putchar(a[0].color);
            puts("");
        } else {
            char out[2] = {a[0].color, a[1].color};
            sort(out, out + 2);
            printf("%c%c\n", out[0], out[1]);
        }
    } else {
        puts("BGR");
    }
    return 0;
}
