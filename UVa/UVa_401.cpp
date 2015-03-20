#include <cstdio>
#include <cstring>

using namespace std;

char r[125], s[1000];

int main()
{
	memset(r, 0, sizeof(r));
	r['A']='A'; r['E']='3'; r['H']='H';
	r['I']='I'; r['J']='L'; r['L']='J';
	r['M']='M'; r['O']='O'; r['S']='2';
	r['T']='T'; r['U']='U'; r['V']='V';
	r['W']='W'; r['X']='X'; r['Y']='Y';
	r['Z']='5'; r['1']='1'; r['2']='S';
	r['3']='E'; r['5']='Z'; r['8']='8';
	
	int i, l;
	char mirror, palin;
	while( gets(s) )
	{
		mirror=palin=1;
		l=strlen(s);
		for( i=0; i<(l>>1); i++ )
		{
			if( s[i]!=s[l-i-1] )
				palin=0;
			if( r[s[i]]!=s[l-i-1] )
				mirror=0;
		}
		if( l%2 && r[s[l>>1]]!=s[l>>1] )
			mirror=0;
		
		if( palin && mirror )
			printf("%s -- is a mirrored palindrome.\n", s);
		else if( palin && !mirror )
			printf("%s -- is a regular palindrome.\n", s);
		else if( !palin && mirror )
			printf("%s -- is a mirrored string.\n", s);
		else if( !palin && !mirror )
			printf("%s -- is not a palindrome.\n", s);
		putchar('\n');
	}
	return 0;
}
