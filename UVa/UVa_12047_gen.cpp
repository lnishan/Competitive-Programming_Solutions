#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

const int T = 20;
const int N = 10000;
const int M = 100000;
const int P = 1000000;
const int C = 100000;

inline int r(const int &lb, const int &ub)
{
	return lb + rand() % (ub - lb + 1);
}

int main()
{
	srand(time(0));
	freopen("input.txt", "w", stdout);
	printf("%d\n", T);
	int i, vs, es, p, st, ed;
	int v1, v2, wt;
	for (i = 0; i < T; i++)
	{
		vs = r(2, N);
		es = r(1, vs * (vs - 1) / 2);
		st = r(1, vs);
		do { ed = r(1, vs); } while (ed == st);
		p = r(1, P);
		printf("%d %d %d %d %d\n", vs, es, st, ed, p);
		while (es--)
		{
			v1 = r(1, vs);
			do { v2 = r(1, vs); } while (v2 == v1);
			wt = r(0, p / (vs / 2));
			printf("%d %d %d\n", v1, v2, wt);
		}
	}
	return 0;
}
