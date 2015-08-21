#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int M = 1200005;

char isP[M];
int cnt1[M], cnt2[M];

int main()
{
    int i, j, sq = sqrt(M);
    int m, d[20], dc;
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    fill(isP, isP + M, 1);
    isP[1] = 0;
    for (i = 2; i <= sq; i++)
        if (isP[i])
            for (j = i * i; j < M; j += i)
                isP[j] = 0;
    for (i = 1; i < M; i++)
        cnt1[i] = cnt1[i - 1] + isP[i];
    for (i = 1; i < M; i++)
    {
        dc = 0;
        for (m = i; m; m /= 10)
            d[dc++] = m % 10;
        for (j = 0; j < dc / 2; j++)
            if (d[j] != d[dc - 1 - j])
                break;
        cnt2[i] = cnt2[i - 1] + (j == (dc / 2));
    }
//    for (i = M - 100; i < M; i++)
//        printf("%d: %d %d\n", i, cnt1[i], cnt2[i]);
    int p, q;
    scanf("%d%d", &p, &q);
    for (i = M - 1; i >= 1; i--)
        if (cnt1[i] * q <= cnt2[i] * p)
            break;
    if (i)
        printf("%d\n", i);
    else
        puts("Palindromic tree is better than splay tree");
    return 0;

}