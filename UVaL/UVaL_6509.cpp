#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
typedef pair<int, int> pii;

const int N = 500002;
const int sqN = sqrt(N);

set<pii> done;
vector<int> lst;
int thres[N], it;

int gcd(int a, int b) {
    while (a && b)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

void pre() {
    int i, x, y, a, b, g;
    for (y = 1; y <= sqN; y++)
        for (x = y + 1; x <= sqN; x++) {
            a = 2 * x * y;
            b = x * x - y * y;
            g = gcd(a, b);
            a /= g;
            b /= g;
            if (a > b) swap(a, b);
            if (done.find(make_pair(a, b)) == done.end()) {
                lst.push_back(2 * (a + b));
                done.insert(make_pair(a, b));
            }
        }
    sort(lst.begin(), lst.end());
    it = 1;
    int cnt = 0;
    thres[0] = 0;
    for (auto &ai: lst) {
        cnt += ai;
        thres[it++] = cnt;
        if (cnt > 1e6) break;
    }
}

int main() {
    pre();
    int i, tt, n;
    scanf("%d", &tt);
    while (tt--) {
        scanf("%d", &n);
        int idx = upper_bound(thres, thres + it, n) - thres;
        printf("%d\n", idx - 1);
    }
    return 0;
}
