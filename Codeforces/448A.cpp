#include <cstdio>

using namespace std;

int main()
{
	int a1, a2, a3, at, b1, b2, b3, bt, need, n;
	scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &b1, &b2, &b3);
	at = a1 + a2 + a3;
	bt = b1 + b2 + b3;
	need = (at / 5) + (at % 5 != 0) + (bt / 10) + (bt % 10 != 0);
	scanf("%d", &n);
	puts( (n >= need) ? "YES" : "NO" );
	return 0;
}
