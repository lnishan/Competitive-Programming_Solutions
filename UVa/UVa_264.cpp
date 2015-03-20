#include <iostream>
using namespace std;
int main()
{
    int n, a, b, c, d;
    while(scanf("%d",&n)!=EOF)
    {
        for (d=1, c=n; c>d; d++) c-=d;
        if ( d%2==1 ) a=d-c+1;
        else a=c;
        b=d+1-a;
        cout << "TERM " << n << " IS " << a << "/" << b << endl;
    }
    return 0;
}
