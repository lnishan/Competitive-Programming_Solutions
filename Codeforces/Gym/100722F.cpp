#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

deque<pii> q; int t = 0;

int main()
{
    int i, j, tt;
    int n, m;
    pii tmp;
    int mx;
    scanf("%d", &tt);
    while (tt--)
    {
        t = 0;
        q.clear();
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &tmp.second);
            tmp.first = i;
            q.push_back(tmp);
        }
        while (!q.empty())
        {
            pii qi = q.front(); q.pop_front();
            mx = qi.second;
            for (auto &qq: q)
                if (qq.second > mx)
                    mx = qq.second;
            if (mx > qi.second)
                q.push_back(qi);
            else
            {
                ++t;
                if (qi.first == m) break;
            }
        }
        printf("%d\n", t);
    }
    return 0;
}
