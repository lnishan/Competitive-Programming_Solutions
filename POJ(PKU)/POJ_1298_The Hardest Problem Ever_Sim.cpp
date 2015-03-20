#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

char s[10002];

int main()
{
	int i, j, l;
	while( gets(s) && strcmp(s, "START")==0 )
	{
		while( gets(s) && strcmp(s, "END")!=0 )
		{
			l=strlen(s);
			for( i=0; i<l; i++ )
				if( isalpha(s[i]) )
					putchar( (((s[i]-'A'-5)+26) %26)+'A' );
				else
					putchar(s[i]);
			putchar('\n');
		}
	}
	return 0;
}
