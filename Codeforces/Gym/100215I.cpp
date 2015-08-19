#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ull;

const int N = 62;

class BigInteger
{
private:
    vector<char> d;
public:
    BigInteger() { d.push_back(0); }
    
    template <typename T>
    BigInteger(T n)
    {
        for (; n; n /= 10)
            d.push_back(n % 10);
    }
    
    template <typename T>
    bool operator == (const T &n)
    {
        BigInteger m(n);
        if (d.size() != m.d.size())
           return false;
        int i;
        for (i = 0; i < d.size(); i++)
            if (d[i] != m.d[i])
               return false;
        return true;
    }
    
    BigInteger operator + (const BigInteger &rhs)const
    {
        int i, mx = max(d.size(), rhs.d.size());
        BigInteger res; res.d.resize(mx + 1);
        for (i = 0; i < mx; i++)
        {
            res.d[i] += 
                     (i < d.size() ? d[i] : 0)
                      + (i < rhs.d.size() ? rhs.d[i] : 0);
            if (res.d[i] > 9)
            {
                res.d[i] -= 10;
                res.d[i + 1]++;
            }
        }
        if (!res.d[mx]) res.d.resize(mx);
        return res;
    }
    
    void print()
    {
        int i;
        for (i = d.size() - 1; i >= 0; i--)
            putchar(d[i] + '0');
    }
};

BigInteger dp[N][N][N];

BigInteger cal(const int &a, const int &b, const int &c)
{
    if (a < 0 || b <0 || c < 0
       || a < b || b < c) return dp[a][b][c] = 0;
    if (!(dp[a][b][c] == 0)) return dp[a][b][c];
    return dp[a][b][c] = cal(a - 1, b, c) + cal(a, b - 1, c) + cal(a, b, c - 1);
}

int main()
{
    freopen("regular.in", "r", stdin);
    freopen("regular.out", "w", stdout);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    int n;
    scanf("%d", &n);
    BigInteger ans = cal(n, n, n);
    ans.print();
    return 0;
}
