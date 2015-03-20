#include <cstdio>
#include <algorithm>

using namespace std;

int f[24][6]={
{0,1,2,3,4,5},
{0,2,3,4,1,5},
{0,3,4,1,2,5},
{0,4,1,2,3,5},
{1,2,0,4,5,3},
{1,0,4,5,2,3},
{1,4,5,2,0,3},
{1,5,2,0,4,3},
{2,0,1,5,3,4},
{2,1,5,3,0,4},
{2,5,3,0,1,4},
{2,3,0,1,5,4}
};
char a[6], s[15];

int main()
{
	int i, j;
	for( i=12; i<24; i++ )
		for( j=0; j<6; j++ )
			f[i][j]=f[i-12][5-j];
	while( gets(s) )
	{
		swap(s[3], s[4]);
		swap(s[9], s[10]);
		for( i=0; i<24; i++ )
		{
			for( j=0; j<6; j++ )
				a[f[i][j]]=s[j];
			for( j=0; j<6; j++ )
				if( a[j]!=s[6+j] )
					break;
			if( j==6 ) break;
		}
		if( i==24 )
			puts("FALSE");
		else
			puts("TRUE");
	}
	return 0;
}
