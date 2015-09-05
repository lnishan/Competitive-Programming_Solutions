#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a[100005];

int main()
{
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        while (a[i] % 2 == 0) a[i] /= 2;
        while (a[i] % 3 == 0) a[i] /= 3;
    }
    for (i = 1; i < n; i++)
        if (a[i] != a[i - 1]) break;
    puts(i < n ? "No" : "Yes");
    return 0;
}
