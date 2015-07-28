#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

struct edge { char type; int to; }; // type = 0 for horizontal
map<int, edge> x;

int main()
{
    int i, n, q;
    int qx, qy; char cmd;
    int to;
    scanf("%d%d", &n, &q);
	x[0] = (edge){ 1, 0 };
	x[n + 1] = (edge){ 0, 0 };
    while (q--)
    {
        scanf("%d%d %c", &qx, &qy, &cmd);
        auto it = x.lower_bound(qx);
        if (it->first == qx) { puts("0"); continue; }
        if (cmd == 'U')
        {
            if (it->second.type)
				to = it->second.to;
			else
				to = n + 1 - it->first;
			printf("%d\n", qy - to);
			x[qx] = (edge){ 1, to };
        }
		else // L
		{
			it--;
			if (it->second.type)
				to = it->first;
			else
				to = it->second.to;
			printf("%d\n", qx - to);
			x[qx] = (edge){ 0, to };
		}
    }
	return 0;
}