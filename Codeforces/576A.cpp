#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int P = 1020;

char isP[P];
vector<int> p;
vector<int> ans;

int main()
{
    int i, j, n;
    fill(isP, isP + P, 1);
    for (i = 2; i * i < P; i++)
        if (isP[i])
            for (j = i * i; j < P; j += i)
                isP[j] = 0;
    for (i = 2; i < P; i++)
        if (isP[i])
            p.push_back(i);
    cin >> n;
    for (auto &pi: p)
    {
        int cnt = 0, pp = pi;
        while (pp <= n)
        {
            ans.push_back(pp);
            cnt++;
            pp *= pi;
        }
    }
    cout << ans.size() << endl;
    for (auto &ai: ans)
        cout << ai << " ";
    return 0;
}
