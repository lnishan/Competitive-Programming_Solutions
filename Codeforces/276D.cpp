#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

int main()
{
    int i;
    cin.tie(0);
    ios::sync_with_stdio(0);
    ull l, r;
    cin >> l >> r;
    for (i = 63; i >= 0; i--)
        if ((l & 1ULL << i) == 0 && (r & 1ULL << i) > 0) break;
    cout << (i >= 0 ? (1ULL << i + 1) - 1 : 0);
    return 0;
}
