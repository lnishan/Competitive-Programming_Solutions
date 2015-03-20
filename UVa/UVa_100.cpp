#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int i, a, b, tn;
	while( scanf("%d %d",&a,&b)==2 )
	{
		printf("%d %d ", a, b);
		if( a>b ){ a+=b; b=a-b; a-=b; }
		long long int maxl=0, tl;
		for( i=a; i<=b; i++ )
		{
			tn=i;
			tl=1;
			while( tn!=1 )
			{
				if( tn%2==1 )
					tn=3*tn+1;
				else
					tn/=2;
				tl++;
			}
			maxl=max(maxl, tl);
		}
		printf("%lld\n", maxl);
    }
    return 0;
}

