#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;

char stk[N]; int top = 0;
int stki[N];
int cnt[N];
char a[N];
char s[N];
char n[130];

int main()
{
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
    int i, l;
    n['('] = 1; n[')'] = -1;
    n['['] = 2; n[']'] = -2;
    int ans = 0, ai, aj;
    gets(a);
    for (i = 0; a[i]; i++) s[i + 1] = n[a[i]];
    l = i; s[0] = 0;
    fill(cnt, cnt + 1 + l, 0);
    for (i = 1; i <= l; i++)
    {
        if (s[i] < 0)
        {
            if (!top || stk[top] != -s[i])
            {
                stk[++top] = s[i];
                stki[top] = i;
            }
            else
            {
                cnt[i] = cnt[stki[top] - 1] + cnt[i - 1] + 1;
                if (cnt[i] > ans)
                {
                    ans = cnt[i];
                    aj = i - 1;
                }
                --top;
            }
        }
        else
        {
            stk[++top] = s[i];
            stki[top] = i;
        }
    }
    ai = aj - ans * 2 + 1;
//    printf("%d\n", ans);
    if (ans)
        for (i = ai; i <= aj; i++)
            putchar(a[i]);
    return 0;
}
