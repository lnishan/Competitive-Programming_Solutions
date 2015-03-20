#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

map<string, int> m;
map<string, int>::iterator it;
struct ss{
	char s[200];
} ssrt[10005];

char s[500000], w[200];

bool cmp( ss a, ss b )
{
	return strcmp(a.s, b.s)<0;
}

int main()
{
	int i, j, n, l, sc, t=0;
while( scanf("%d", &n)==1 )
{
	if( t++>0 ) putchar('\n');
	m.clear();
	sc=0;
	for( i=0; i<10005; i++ )
		ssrt[i].s[0]='\0';
	scanf("%d", &n);
	scanf("\n");
	while( gets(s) && strcmp(s, "EndOfText")!=0 )
	{
		l=strlen(s);
		for( i=0; i<l; i++ )
			if( isupper(s[i]) )
				s[i]=tolower(s[i]);
		
		for( i=0; i<l; )
		{
			j=0;
			for( ; !isalpha(s[i]) && i<l; i++ );
			if( i==l ) break;
			w[j++]=s[i];
			for( i=i+1; isalpha(s[i]) && i<l; i++ )
				w[j++]=s[i];
			w[j]='\0';
			it=m.find(w);
			if( it==m.end() )
				m[w]=1;
			else
				m[w]++;
		}
	}
	for( it=m.begin(); it!=m.end(); it++ )
		if( (*it).second==n )
			strcat(ssrt[sc++].s, (*it).first.c_str());
	sort(ssrt, ssrt+sc, cmp);
	for( i=0; i<sc; i++ )
		puts(ssrt[i].s);
	if( sc==0 )
		puts("There is no such word.");
}
	return 0;
}
