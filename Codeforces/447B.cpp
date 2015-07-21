#include <cstdio>
#include <cstring>
#define MAX 1005

using namespace std;

char s[MAX];
int pt[30];

int main()
{
	int i, l, k, mx=-1, ans=0;
	gets(s);
	l=strlen(s);
	scanf("%d", &k);
	for( i=0; i<26; i++ )
	{
		scanf("%d", &pt[i]);
		if( pt[i]>mx )
			mx=pt[i];
	}
	for( i=1; i<=l; i++ )
		ans+=pt[s[i-1]-'a']*i;
	for( i=1; i<=k; i++ )
		ans+=mx*(l+i);
	printf("%d\n", ans);
	return 0;
}
