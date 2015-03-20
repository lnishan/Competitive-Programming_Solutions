#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#define MAX 102

using namespace std;

int judge(char *a, char *b) // 1=a wins, -1=b wins, 0=draw
{
	if( strcmp(a, b)==0 )
		return 0;
	if( strcmp(a, "rock")==0 )
	{
		if( strcmp(b, "scissors")==0 )
			return 1;
		else
			return -1;
	}
	else if( strcmp(a, "scissors")==0 )
	{
		if( strcmp(b, "paper")==0 )
			return 1;
		else
			return -1;
	}
	else // paper
	{
		if( strcmp(b, "rock")==0 )
			return 1;
		else
			return -1;
	}
}

int w[MAX], l[MAX];
char s1[10], s2[10];

int main()
{
	int i, n, k, a, b, tot, ret;
	char f=0;
	while( scanf("%d", &n)==1 && n>0 )
	{
		if( f )
			puts("");
		f=1;
		for( i=1; i<=n; i++ )
			w[i]=l[i]=0;
		scanf("%d", &k);
		tot=k * n*(n-1)/2;
		while( tot-- )
		{
			scanf("%d %s %d %s", &a, &s1, &b, &s2);
			ret=judge(s1, s2);
			if( ret==1 )
			{
				w[a]++;
				l[b]++;
			}
			else if( ret==-1 )
			{
				l[a]++;
				w[b]++;
			}
		}
		for( i=1; i<=n; i++ )
		{
			tot=w[i]+l[i];
			if( tot==0 )
				puts("-");
			else
				printf("%.3f\n", float(w[i])/tot);
		}
	}
	return 0;
}
