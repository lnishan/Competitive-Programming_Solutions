#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2005;
const int M = 5005;


int a[N];

double p[5005];
double gp[5005];

int main() {
    int i, j, n;
    for (i = 0; i < M; i++) p[i] = gp[i] = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (j = 0; j < i; j++)
            p[abs(a[i] - a[j])]++;
    }
    double ppp = 0;
    for (i = M - 2; i >= 0; i--)
        gp[i] = gp[i + 1] + p[i];
    for (i = 0; i < M; i++)
        for (j = 0; i + j + 1 < M; j++)
            ppp += p[i] * p[j] * gp[i + j + 1];
    ll nn = n;
    double tmp = nn * (nn - 1) / 2;
    double pppp = tmp * tmp * tmp;
    printf("%.17f\n", ppp / pppp);
    return 0;
}
