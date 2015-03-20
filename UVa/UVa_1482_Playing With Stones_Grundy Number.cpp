 #include <cstdio>

using namespace std;

typedef unsigned long long int LLU;

LLU grundy(LLU n)
{
    if (n < 2) return 0;
    if (n % 2)
        return grundy(n >> 1);
    else
        return n >> 1;
}

int main()
{
    int i, t, n;
    LLU ai, g;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%llu", &ai);
        g = grundy(ai);
        while (--n)
        {
            scanf("%llu", &ai);
            g ^= grundy(ai);
        }
        puts( g == 0 ? "NO" : "YES" );
    }
    return 0;
}
