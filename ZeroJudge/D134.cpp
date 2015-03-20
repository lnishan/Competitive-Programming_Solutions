#include<cstdio>

using namespace std;

int main(){
    int i, n, m, t;
    unsigned long long int ans;
    while( scanf("%d%d", &n, &m)==2 && !(n==0 && m==0) )
    {
        t=m;
        ans=1;
        if( m>n/2 ) m=n-m;
        for( i=0; i<m; i++)
            if( ans%(i+1)==0 )
            {
                ans/=(i+1);
                ans*=(n-i);
            }
            else
                ans=ans*(n-i)/(i+1);
        printf("%d things taken %d at a time is %llu exactly.\n", n, t, ans);
    }
    return 0;
}
