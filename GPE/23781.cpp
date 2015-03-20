#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int m[6][2], du[202], dl[702];

int main()
{
	int i, j, k, p, ans;
	double inp;
	
	m[0][0]=5;
	m[1][0]=10;
	m[2][0]=20;
	m[3][0]=50;
	m[4][0]=100;
	m[5][0]=200;
	memset(du, -1, sizeof(du));
	du[0]=0;
	for( i=0; i<6; i++ )
		for( j=m[i][0]; j<=200; j+=5 )
			if( du[j-m[i][0]]>=0 )
			{
				if( du[j]<0 || du[j-m[i][0]]+1<du[j] )
					du[j]=du[j-m[i][0]]+1;
			}
	
	while( scanf("%d%d%d%d%d%d", &m[0][1], &m[1][1], &m[2][1], &m[3][1], &m[4][1], &m[5][1])==6 )
	{
		ans=2147483647;
		memset(dl, -1, sizeof(dl));
		dl[0]=0;
		for( i=0; i<6; i++ )
			if( m[i][1]>0 ) break;
		if( i==6 ) break;
		scanf("%lf", &inp);
		inp=inp*100+1e-10;
		p=inp;
		for( i=0; i<6; i++ )
			for( k=0; k<m[i][1]; k++ )
				for( j=p+200; j>=m[i][0]; j-=5 )
					if( dl[j-m[i][0]]>=0 )
					{
						if( dl[j]<0 || dl[j-m[i][0]]+1<dl[j] )
							dl[j]=dl[j-m[i][0]]+1;
					}
		for( i=p; i<=p+200; i++ )
			if( dl[i]>=0 )
				ans=min(ans, dl[i]+du[i-p]);
		printf("%3d\n", ans);
	}
	return 0;
}
