#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int i, j, t, n, c, m, a, b;
    scanf("%d", &t);
    for( j=1; j<=t; j++ )
    {
        c=0;
        m=4000;
        scanf("%d", &n);
        for( i=0; i<n; i++ )
        {
            scanf("%d%d", &a, &b);
            m=min(m, a*60+b);
            c+=a*60+b;
        }
        c/=n;
        printf("Track %d:\n", j);
        printf("Best Lap: %d minute(s) %d second(s).\n", m/60, m%60);
        printf("Average: %d minute(s) %d second(s).\n\n", c/60, c%60);
    }
    return 0;
}
