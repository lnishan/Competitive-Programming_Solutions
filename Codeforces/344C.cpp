#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull cal(ull a, ull b)
{
    ull ret = a / b;
    a %= b;
    if (!a) return ret;
    return ret + (a == 1 ? b : cal(a, b % a) + b / a);
}


int main()
{
    ios::sync_with_stdio(0);
    ull a, b;
    cin >> a >> b;   
    cout << cal(a, b);
    return 0;
}
