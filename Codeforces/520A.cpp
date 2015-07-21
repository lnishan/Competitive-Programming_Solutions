#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

const int N = 105;
char s[N];
int cnt[130];

int main()
{
	int i, l;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &l);
	scanf(" ");
	gets(s);
	l = strlen(s);
	for (i = 0; i < l; i++)
		cnt[ tolower(s[i]) ] ++;
	for (i = 'a'; i <= 'z'; i++)
		if (!cnt[i]) break;
	puts( i > 'z' ? "YES" : "NO" );
	return 0;
}
