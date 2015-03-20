#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

struct ch{
	char c;
	int pos;
} ss[105];

char s[105], s2[105], sa[105];

int main()
{
	int i, j, t, l, l2;
	scanf("%d", &t);
	scanf("\n");
	while( t-- )
	{
		gets(s);
		l=strlen(s);
		for( i=0; i<l; i++ )
		{
			ss[i].c=s[i];
			ss[i].pos=i;
		}
		for( i=l-2; i>=0; i-- )
			for( j=0; j<=i; j++ )
				if( ss[j].c>ss[j+1].c )
					swap(ss[j], ss[j+1]);

		gets(s2);
		l2=strlen(s2);
		for( i=0; i+l-1<l2; i+=l )
			for( j=0; j<l; j++ )
				sa[i+j]=s2[i+ss[j].pos];

		l=l2%l;
		if( l>0 )
		{
			for( i=0; i<l; i++ )
			{
				ss[i].c=s[i];
				ss[i].pos=i;
			}
			for( i=l-2; i>=0; i-- )
				for( j=0; j<=i; j++ )
					if( ss[j].c>ss[j+1].c )
						swap(ss[j], ss[j+1]);
			for( i=l2-l; i<l2; i++ )
				sa[i]=s2[l2-l+ss[i-(l2-l)].pos];
		}
		sa[l2]='\0';
		puts(sa);
	}
	return 0;
}
