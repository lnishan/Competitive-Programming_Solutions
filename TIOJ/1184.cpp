#include <iostream>

using namespace std;

struct comp{
    int price, amount;
} a[200];

bool cmp(comp a, comp b){
    return a.price<b.price;
}

int main(){
    int i, t, n, m, c;
    scanf("%d", &t);
    while( t-- )
    {
        c=0;
        scanf("%d%d", &n, &m );
        for( i=0; i<n; i++ )
            scanf("%d%d", &a[i].price, &a[i].amount);
        sort(a, a+n, cmp);
        for( i=0; i<n; i++ )
        {
            if( m>=a[i].amount )
            {
                m-=a[i].amount;
                c+=a[i].amount*a[i].price;
            }
            else
            {
                c+=m*a[i].price;
                m=0;
            }
        }
        if( m>0 )
            puts("so sad");
        else
            printf("%d\n", c);
    }
    return 0;
}