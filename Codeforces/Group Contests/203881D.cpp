#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100005;

int f[N], id[N], loc[N];

int findF(int i)
{
    return f[i] == i ? i : (f[i] = findF(f[i]));
}

void uniF(int i, int j)
{
    f[findF(j)] = findF(i);
}

int main()
{
    int i, n, q;
    int s, t;
    scanf("%d%d", &n, &q);
    for (i = 1; i <= n; i++) f[i] = id[i] = loc[i] = i;
    while (q--)
    {
        scanf("%d%d", &s, &t);
        if (!id[t]) // empty
        {
            id[t] = id[s];
            loc[id[s]] = t;
            id[s] = 0;
        }
        else
        {
            uniF(id[t], id[s]);
            id[s] = 0;
        }
    }
    for (i = 1; i <= n; i++)
        printf("%d ", loc[findF(i)]);
    return 0;
}
