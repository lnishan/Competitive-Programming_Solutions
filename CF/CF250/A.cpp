#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct opt
{
	char o;
	int l;
	bool operator <(const opt &rhs)const
	{
		return l<rhs.l;
	}
} l[4];

int main()
{
	char s[120], o[4]={'A', 'B', 'C', 'D'};
	int i;
	for( i=0; i<4; i++ )
	{
		gets(s);
		l[i]=(opt){o[i], strlen(s)-2};
	}
	sort(l, l+4);
	if( (l[0].l<<1)<=l[1].l && l[3].l>=(l[2].l<<1) )
		putchar('C');
	else if( (l[0].l<<1)<=l[1].l )
		putchar(l[0].o);
	else if( l[3].l>=(l[2].l<<1) )
		putchar(l[3].o);
	else
		putchar('C');
	return 0;
}


