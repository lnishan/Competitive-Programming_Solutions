#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char vst[1000005];

int main()
{
    int i, n;
    memset(vst, 0, sizeof(vst));
    char cmd; int id;
    int cnt = 0, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c%d", &cmd, &id);
        if (cmd == '+')
        {
            vst[id] = 1;
            cnt++;
            ans = max(ans, cnt);
        }
        else if (cmd == '-')
        {
            if (!vst[id])
               ans = ans + 1;
            else
            {
                vst[id] = 0;
                cnt--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
