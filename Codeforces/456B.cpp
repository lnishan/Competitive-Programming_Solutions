#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

char s[100005];

int main()
{
    int l, m;
    gets(s); l = strlen(s);
    m = (l == 1 ? s[0] - '0' : (s[l - 2] - 48) * 10 + s[l - 1] - 48) % 4;
    puts(m % 4 ? "0" : "4");
    return 0;
}
