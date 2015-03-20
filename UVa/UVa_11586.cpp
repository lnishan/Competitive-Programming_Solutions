#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char s[200], *ptr;
	int i, t, mf, fm, mm, ff;
	scanf("%d", &t);
	scanf("\n");
	while( t-- )
	{
		mf=fm=mm=ff=0;
		gets(s);
		ptr=strtok(s, " ");
		while( ptr!=NULL )
		{
			if( strcmp(ptr, "MF")==0 )
				mf++;
			else if( strcmp(ptr, "FM")==0 )
				fm++;
			else if( strcmp(ptr, "MM")==0 )
				mm++;
			else if( strcmp(ptr, "FF")==0 )
				ff++;
			ptr=strtok(NULL, " ");
		}
		if( mf+fm+mm+ff==1 )
			puts("NO LOOP");
		else if( mm!=ff )
			puts("NO LOOP");
		else
		{
			if( mf && fm && !mm && !ff )
				puts("NO LOOP");
			else
				puts("LOOP");
		}
	}
	return 0;
}
