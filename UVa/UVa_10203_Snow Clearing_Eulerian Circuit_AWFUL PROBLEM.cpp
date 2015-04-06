#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double v = 20 * 1000 / 60.0f;
char s[202];

int main()
{
	int i, tt, e, x1, y1, x2, y2;
	double tot, t;
	scanf("%d", &tt);
	while (tt--)
	{
		tot = 0;
		scanf("%d%d", &x1, &y1);
		scanf(" ");
		while (gets(s) && strlen(s) > 0)
		{
			sscanf(s, "%d%d%d%d", &x1, &y1, &x2, &y2);
			tot += sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) * 2;
		}
		t = round(tot / v);
		printf("%d:%02d\n", int(t) / 60, int(t) % 60);
		if (tt) puts("");
	}
	return 0;
}
