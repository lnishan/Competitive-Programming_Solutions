#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using namespace std;

struct data{
	char s[85];
} p[500], tmp;
int r[500][500], st[500], stc=0, nc=0;
map<string, int> mp;
map<string, int>::iterator it;
string sn[500];

void dfs(int sps, int ii)
{
	int i;
	for( i=0; i<sps; i++ ) putchar(' ');
	cout << sn[ii] << endl;
	for( i=0; i<nc; i++ )
		if( r[ii][i]==1 )
		{
			r[ii][i]=0;
			dfs(sps+1, i);
		}
	return ;
} 

bool cmp( data a, data b )
{
	int r;
	char *p1, *p2;
	p1=strtok(a.s, "\\"); p2=strtok(b.s, "\\");
	while( p1!=NULL && p2!=NULL )
	{
		r=strcmp(p1, p2);
		if( r!=0 )
			return r<0;
		p1=strtok(NULL, "\\"); p2=strtok(NULL, "\\");
	}
	return p2==NULL;
}

int main()
{
	int i, j, n, pri, ni;
	char *ptr;
	memset(r, 0, sizeof(r));
	scanf("%d", &n);
	scanf("\n");
	for( i=0; i<n; i++ )
		gets(p[i].s);
	//sort(p, p+n, cmp);
	for( i=n-2; i>=0; i-- )
		for( j=0; j<=i; j++ )
			if( !cmp(p[j], p[j+1]) )
			{
				tmp=p[j];
				p[j]=p[j+1];
				p[j+1]=tmp;
			}
	//data t, t2; strcat(t.s,"WINNT\\SYSTEM32\\CONFIG"); strcat(t2.s,"WINNT\\SYSTEM32\\CERT");
	//cout << cmp(t, t2);
	//for( i=0; i<n; i++ ) puts(p[i].s);
	for( i=0; i<n; i++ )
	{
		ptr=strtok(p[i].s, "\\");
		it=mp.find(ptr);
		if( it==mp.end() )
		{
			mp[ptr]=nc;
			sn[nc]=ptr;
			st[stc++]=nc;
			pri=nc++;
		}
		else
			pri=(*it).second;
		ptr=strtok(NULL, "\\");
		while( ptr!=NULL )
		{
			it=mp.find(ptr);
			if( it==mp.end() )
			{
				mp[ptr]=nc;
				sn[nc]=ptr;
				ni=nc++;
			}
			else
				ni=(*it).second;
			r[pri][ni]=1;
			pri=ni;
			ptr=strtok(NULL, "\\");
		}
	}
	for( i=0; i<stc; i++ )
		dfs(0, st[i]);
	
	//while(1);
	return 0;
}
