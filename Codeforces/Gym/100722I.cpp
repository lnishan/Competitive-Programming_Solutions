#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char c[30];
char nxt[130];
char used[130];
int cnt[30];

int main()
{
    int i, tt;
    int tmp;
    char vi;
    scanf("%d ", &tt);
    while (tt--)
    {
        memset(used, 0, sizeof(used));
        memset(cnt, 0, sizeof(cnt));
        gets(c);
        for (i = 0; c[i]; i++) nxt['A' + i] = c[i];
        for (i = 'A'; i <= 'Z'; i++)
        {
            if (used[i]) continue;
            used[i] = 1;
            for (vi = i, tmp = 1; nxt[vi] != i; used[vi] = 1, vi = nxt[vi]) tmp++;
            used[vi] = 1;
            if (tmp % 2 == 0)
                cnt[tmp]++;
        }
        for (i = 0; i < 30; i += 2)
            if (cnt[i] & 1)
                break;
        puts( i == 30 ? "Yes" : "No" );
    }
    return 0;
}
