#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10005;
const int SQ = sqrt(N);
const int inf = 1e9;

char isP[N];
int stp[N];
struct state { int n[4]; } tmp;
queue<state> q;
int ten[] = {1, 10, 100, 1000, 10000};

inline int get_n(state s)
{
    int i, ret = 0;
    for (i = 0; i < 4; i++) ret += s.n[i] * ten[i];
    return ret;
}

int main()
{
    int i, j;
    int s, t;
    int tt;
    fill(isP, isP + N, 1);
    isP[0] = isP[1] = 0;
    for (i = 2; i < N; i++)
        if (isP[i])
            for (j = i * i; j < N; j += i)
                isP[j] = 0;
    scanf("%d", &tt);
    while (tt--)
    {
        while (!q.empty()) q.pop();
        fill(stp, stp + N, inf);
        scanf("%d%d", &s, &t);
        for (i = 0; i < 4; i++) tmp.n[i] = (s % ten[i + 1]) / ten[i];
        stp[s] = 0;
        q.push(tmp);
        while (!q.empty())
        {
            state qs = q.front(); q.pop();
            int qn = get_n(qs);
            for (i = 0; i < 4; i++)
                for (j = (i < 3 ? 0 : 1); j < 10; j++)
                {
                    if (j == qs.n[i]) continue;
                    int tmp = qs.n[i];
                    qs.n[i] = j;
                    int nn = get_n(qs);
                    if (isP[nn] && stp[qn] + 1 < stp[nn])
                    {
                        stp[nn] = stp[qn] + 1;
                        q.push(qs);
                    }
                    qs.n[i] = tmp;
                }
        }
        if (stp[t] == inf)
            puts("Impossible");
        else
            printf("%d\n", stp[t]);
    }
    return 0;
}
