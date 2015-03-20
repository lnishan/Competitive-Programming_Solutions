 #include <cstdio>
#include <cstring>
#define MAX 202

using namespace std;

int g[MAX][MAX];
char used[MAX<<1];

int grundy(int w, int h)
{
	int &cur = g[w][h];
	if (cur != -1) return cur;
	if (w == 1 || h == 1) return cur = 1;
	if (w <= 3 && h <= 3) return cur = 0;
	int i, j;
	memset(used, 0, sizeof(used));
	for (i = 2; i <= w-2; i++)
		used[ grundy(i, h) ^ grundy(w-i, h) ] = 1;
	for (i = 2; i <= h-2; i++)
		used[ grundy(w, i) ^ grundy(w, h-i) ] = 1;
	for (i = 0; i < (MAX<<1); i++)
		if (!used[i])
			return cur = i;
}

int main()
{
	int w, h;
	memset(g, -1, sizeof(g));
	while (scanf("%d%d", &w, &h) == 2)
		puts( grundy(w, h) == 0 ? "LOSE" : "WIN" );
	return 0;
}
