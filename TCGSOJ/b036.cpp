#include <iostream>
#include <queue>

using namespace std;

struct node{
    int n;
    inline bool operator < (const node &b)const
    {
        return n>b.n;
    }
} t;
priority_queue<node> q;

int main(){
    int i, n, a, ans;
    while( scanf("%d", &n)==1 )
    {
        ans=0;
        while( q.size()>0 ) q.pop();
        for( i=0; i<n; i++ )
        {
            scanf("%d", &a);
            t.n=a;
            q.push(t);
        }
        for( i=1; i<n; i++ )
        {
            t.n=q.top().n;
            ans+=q.top().n;
            q.pop();
            t.n+=q.top().n;
            ans+=q.top().n;
            q.pop();
            q.push(t);
        }
        printf("%d\n", ans);
    }
    return 0;
}
