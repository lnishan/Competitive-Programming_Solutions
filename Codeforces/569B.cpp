#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100005;

int a[N];
int cnt[N];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int i, n;
    queue<int> q;
    fill(cnt, cnt + N, 0);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        if ((cnt[a[i]] - 1) || a[i] > n) a[i] = 0;
    }
    for (i = 1; i <= n; i++)
        if (!cnt[i])
            q.push(i);
    for (i = 0; i < n; i++)
        if (a[i])
            cout << a[i] << " ";
        else
        {
            cout << q.front() << " ";
            q.pop();
        }
    return 0;
}
