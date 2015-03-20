#include <cstdio>

using namespace std;

int main()
{
    int i, n, p, tmp;
    while (scanf("%d", &n) == 1)
    {
        tmp = 0;
        while ( n-- )
        {
            scanf("%d", &p);
            tmp ^= p;
        }
        puts( (tmp == 0) ? "No" : "Yes" );
    }
    return 0;
}
