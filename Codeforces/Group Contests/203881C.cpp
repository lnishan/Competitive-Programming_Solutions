/* 
if (b0 + b3 + ... + b3n == sum
 && b1 + b4 + ... + b3n+1 == sum
 && b2 + b5 + ... + b3n+2 == sum)
There exists a solution for any (a0, a1) = (x, y) where x, y can be any value
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

const int N = 1000005;

int n;
ll a[N];
ll b[N];
ll s1[N], s2[N];

inline int pr(int i) { return ((i - 1) + n) % n; }
inline int nx(int i) { return (i + 1) % n; }

void filla(int idx)
{
    int i;
    a[idx] = b[idx] / 3 + (b[idx] % 3 != 0);
    for (i = 1, idx = (idx + 3) % n; i < n; i++, idx = (idx + 3) % n)
        a[idx] = a[(idx - 3 + n) % n] + b[pr(idx)] - b[pr(pr(idx))];
}

void filla2(int idx)
{
    int i;
    for (i = 0; i < n; i++, idx = (idx + 3) % n)
        a[idx] = b[pr(idx)] - a[pr(idx)] - a[pr(pr(idx))];
}

int main()
{
    int i, j;
    ll sum = 0;
    ll tmp;
    scanf("%d", &n);
    for (i = 0; i < n; s1[i] = s2[i] = b[i], sum += b[i], i++)
    {
        scanf("%I64d", &b[i]);
//        if (b[i] > 3000000000ULL) break;
    }
    if (i < n || sum % 3)
    {
        puts("-1");
        return 0;
    }
    sum /= 3;
    for (i = 3; i < n; i++) s1[i] += s1[i - 3];
    for (i = n - 4; i >= 0; i--) s2[i] += s2[i + 3];
    if (n % 3 == 0)
    {
        if (s1[n - 1] != sum || s1[n - 2] != sum || s1[n - 3] != sum)
        {
            puts("-1");
            return 0;
        }
        ll mx[3] = {0, 0, 0}; int mx_i[3];
        for (i = 0; i < n; i++)
            if (b[i] > mx[i % 3])
                mx[i % 3] = b[i], mx_i[i % 3] = i;
        if (mx[0] <= mx[1] && mx[0] <= mx[2])
            filla(mx_i[1]), filla(mx_i[2]), filla2(mx_i[0]);
        else if (mx[1] <= mx[0] && mx[1] <= mx[2])
            filla(mx_i[0]), filla(mx_i[2]), filla2(mx_i[1]);
        else
            filla(mx_i[0]), filla(mx_i[1]), filla2(mx_i[2]);
//        for (i = 0; i < n; i++)
//            if (abs(a[j]) >= 1e9)
//                break;
        if (i < n)
            puts("-1");
        else
            for (i = 0; i < n; i++)
                printf("%I64d ", a[i]);
    }
    else if (n % 3 == 1)
    {
        for (i = 0; i < n; i++)
            printf("%I64d ", sum
                 - (i - 2 >= 0 ? s1[i - 2] : 0)
                  - (i + 2 < n ? s2[i + 2] : 0));
    }
    else // if (n % 3 == 2)
    {
        for (i = 0; i < n; i++)
            printf("%I64d ", (i - 1 >= 0 ? s1[i - 1] : 0)
                 + (i + 1 < n ? s2[i + 1] : 0)
                  - sum);
    }
    return 0;
}
