#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

map<int, int> s;
char t[300005];

inline int get_cnt(int n)
{
    return n ? n - 1 : 0;
}

int main()
{
    int i, j, n, q;
    int cnt = 0;
    int pos; char ch;
    int s1, s2, l1, l2;
    scanf("%d%d ", &n, &q);
    s[-1] = 0; s[n] = 0;
    gets(t);
    for (i = 0; t[i]; i++)
        if (t[i] == '.')
        {
            for (j = i + 1; t[j] && t[j] == '.'; j++) ;
            s[i] = j - i;
            cnt += j - i - 1;
            i = j - 1;
        }
    while (q--)
    {
        scanf("%d %c", &pos, &ch); --pos;
        if (ch != '.')
        {
            if (t[pos] == '.')
            {
                t[pos] = ch;
                auto it = s.upper_bound(pos); it--;
                s1 = it->first; l1 = pos - it->first;
                s2 = pos + 1; l2 = it->first + it->second - pos - 1;
                cnt = cnt - get_cnt(it->second)
                     + get_cnt(l1)
                     + get_cnt(l2);
                s.erase(it);
                if (l1) s[s1] = l1;
                if (l2) s[s2] = l2;
            }
        }
        else
        {
            if (t[pos] != '.')
            {
                t[pos] = ch;
                s1 = pos; l1 = 1;
                auto it = s.lower_bound(pos);
                if (it->first < n)
                {
                    if (it->first == pos + 1)
                    {
                        cnt -= get_cnt(it->second);
                        s1 = pos;
                        l1 = it->second + 1;
                        s.erase(it);
                    }
                }
                it = s.lower_bound(pos); it--;
                if (it->first >= 0 && it->first + it->second == pos)
                {
                    cnt -= get_cnt(it->second);
                    s1 = it->first;
                    l1 += it->second;
                    s.erase(it);
                }
                cnt += get_cnt(l1);
                s[s1] = l1;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
