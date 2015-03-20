#include <cstdio>
#define MAX 80002

using namespace std;

int stk[MAX];

int main()
{
    int i, n, h;
    long long int cnt, top = 0, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &h);
        if (top <= 0 || h < stk[top])
            stk[++top] = h;
        else
        {
            cnt = 0;
            while (top && h >= stk[top])
            {
                ans += cnt++;
                top--;
            }
            ans += top * cnt;
            stk[++top] = h;
        }
    }
    ans += ( (top-1) * top ) >> 1;
    printf("%I64d\n", ans);
    return 0;
}
