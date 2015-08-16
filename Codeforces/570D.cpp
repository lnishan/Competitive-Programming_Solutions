#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int N = 500000;
const int lgN = 22;

int n, m;
int pr[N];
vector<int> g[N];
int c[N][lgN][2];
int itD[N]; 
int di[N];
vector<vector<int> > b[26];

void dfs(int d, int vi)
{
    int i, maxd = d;
    di[vi] = itD[d]++;
    for (auto &vj: g[vi])
        maxd = max(maxd, dfs(d + 1, vj));
    if (!g[vi].empty())
    {
        c[vi][0][0] = g[vi][0];
        c[vi][0][1] = g[vi][g[vi].size() - 1];
        for (i = 1; (1 << i) <= d; i++)
        {
            c[vi][i][0] = c[ c[vi][i - 1][0] ][i - 1][0];
            c[vi][i][1] = c[ c[vi][i - 1][1] ][i - 1][1];
        }
    }
    return maxd;
}
    

int main()
{
    int i, j, p;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        itD[i] = 0;
        for (j = 0; j < lgN; j++) c[i][j][0] = c[i][j][1] = -1;
    }
    for (i = 2; i <= n; i++)
    {
        scanf("%d", &p);
        pr[i] = p;
        g[p].push_back(i);
    }
    int maxd = dfs(1, 1);
    for (i = 0; i < 26; i++) b[i].resize(maxd + 1);
    for (i = 0; i < 26; i++)
        for (j = 1; j <= maxd; j++)
            b[i][j].resize(di[j] + 1);
    return 0;
}
