#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int a[502][502];
map<int, int> mp;
vector<int> ans;

int gcd(int a, int b)
{
    while (a && b)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int main()
{
    int i, j, n;
    priority_queue<int> pq;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            mp[a[i][j]]++;
            pq.push(a[i][j]);
        }
    for (i = 0; i < n; i++)
    {
        while (!mp[pq.top()])
            pq.pop();
        int qi = pq.top(); pq.pop();
        mp[qi]--;
        for (auto &ai: ans)
            mp[gcd(qi, ai)] -= 2;
        ans.push_back(qi);
    }
    for (auto &ai: ans)
        printf("%d ", ai);
    return 0;
}
