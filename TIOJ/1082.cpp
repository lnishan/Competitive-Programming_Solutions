#include <iostream>

using namespace std;

int main(){
    int i, n, b, w, miabs, bc, wc, ans;
    while( scanf("%d", &n)==1 && n>0 )
    {
        bc=n; wc=0;
        scanf("%d%d", &b, &w);
        if( n==1 && b!=0 && w!=0 )
            puts("-1");
        else
        {
            miabs=abs(b-w);
            ans=w; if( b<w ){ ans=ans-w+b; bc--; wc++; }
            for( i=1; i<n; i++ )
            {
                scanf("%d%d", &b, &w);
                miabs=min(miabs, abs(b-w));
                ans+=w;
                if( b<w )
                {
                    ans=ans-w+b;
                    bc--; wc++;
                }
            }
            if( (bc==0 || wc==0) && n>1 ) ans+=miabs;
            printf("%d\n", ans);
        }
    }
    return 0;
}