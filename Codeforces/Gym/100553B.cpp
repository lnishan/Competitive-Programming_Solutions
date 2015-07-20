#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100005;
const int inf = 1e9 + 7;

struct node { int g, a, b; int i; };
node ing[N];
double used[N];

int main()
{
	freopen("burrito.in", "r", stdin);
	freopen("burrito.out", "w", stdout);
//	freopen("10", "r", stdin);
//	freopen("10.txt", "w", stdout);
	int i, j, n, A, B;
	double remB, qty, ansA;
	scanf("%d%d%d", &n, &A, &B);
	for (i = 0; i < n; ing[i].i = i, i++)
		scanf("%d%d%d", &ing[i].g, &ing[i].a, &ing[i].b);
	sort(ing, ing + n, [](node a, node b) { return !a.b && !b.b ? a.a > b.a : a.a * b.b > a.b * b.a; });
//	for (i = 0; i < n; i++) printf("%d %d %d\n", ing[i].g, ing[i].a, ing[i].b);
	for (i = 0; i < n && ing[i].a; i++) ;
//	printf("a = 0 from %d\n", i);
	remB = B;
	ansA = 0;
	fill(used, used + n, 0);
	for (i = 0; i < n && remB >= 0.0; i++)
	{
		if (ing[i].a == 0 && ing[i].b != 0) break;
		qty = min((double)ing[i].g, ing[i].b ? remB / ing[i].b : inf);
		used[ing[i].i] += qty;
		remB -= ing[i].b * qty;
		ansA += ing[i].a * qty;
//		printf("remB = %f\n", remB);
	}
//	printf("break from %d\n", i);
	if (A - ansA > 1e-7)
		puts("-1 -1");
	else
	{
		printf("%.17f %.17f\n", ansA, (double)B - remB);
		for (i = 0; i < n; i++)
			printf("%.17f ", used[i]);
		puts("");
	}
	return 0;
}
		
