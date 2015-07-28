#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

pii a[100005];

int main()
{
	int i, nxt_i, j, n, tot = 0, big, add, tmp, ans = 1e9 + 7;
	priority_queue<int> pq;
	vector<int> popped;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i].first);
	for (i = 0; i < n; tot += a[i].second, i++)
		scanf("%d", &a[i].second);
	sort(a, a + n, [](pii a, pii b) { return a.first < b.first; });
//	for (i = 0; i < n; i++) printf("%4d ", a[i].first); puts("");
//	for (i = 0; i < n; i++) printf("%4d ", a[i].second); puts("");
	for (i = 0; i < n; i++)
	{
		big = a[i].second;
		for (j = i + 1; j < n && a[i].first == a[j].first; j++) big += a[j].second;
		nxt_i = j - 1;
		popped.clear();
		add = min(j - i - 1, (int)pq.size());
		for (j = 0; j < add; j++)
		{
			popped.push_back(pq.top());
			big += pq.top();
			pq.pop();
		}
		ans = min(ans, tot - big);
		for (j = 0; j < add; j++) pq.push(popped[j]);
		for (j = i; j < n && a[i].first == a[j].first; j++) pq.push(a[j].second);
		i = nxt_i;
	}
	printf("%d\n", ans);
}