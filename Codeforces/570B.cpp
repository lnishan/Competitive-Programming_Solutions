#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (n == 1)
        puts("1");
    else if (m - 1 >= n - m)
        cout << m - 1;
    else
        cout << m + 1;
    return 0;
}
