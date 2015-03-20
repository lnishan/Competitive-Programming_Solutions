#include <cstdio>

using namespace std;

struct node{
	int l, r;
} t[30];
int ii;
char pr[30], pi[30], pos[30];

void dfs(char f, int l, int r)
{
	int i, m=pos[f-65];
	for( i=l; i<m; i++ )
		if( pi[i]==pr[ii] )
			break;
	if( i<m )
	{
		ii++;
		t[f-65].l=pi[i]-65;
		if( m>l )
			dfs( pi[i], l, m-1 );
	}
	for( i=m+1; i<=r; i++ )
		if( pi[i]==pr[ii] )
			break;
	if( i<=r )
	{
		ii++;
		t[f-65].r=pi[i]-65;
		if( m<r )
			dfs( pi[i], m+1, r );
	}
	return ;
}

void dfs2(int i)
{
    if( t[i].l>=0 ) dfs2(t[i].l);
    if( t[i].r>=0 ) dfs2(t[i].r);
    putchar(i+65);
    if( i!=pr[0]-65 ) putchar(' ');
    return ;
}

int main()
{
	int i, m, n, sp;
	scanf("%d", &m);
	while( m-- )
	{
        for( i=0; i<30; i++)
        {
            t[i].l=-1;
            t[i].r=-1;
        }
		scanf("%d", &n);
		scanf("\n");
		for( i=0; i<n; i++ )
			scanf(" %c", &pr[i]);
		scanf("\n");
		for( i=0; i<n; i++ )
		{
			scanf(" %c", &pi[i]);
			pos[pi[i]-65]=i;
		}
		ii=1;
		dfs(pr[0], 0, n-1);
		dfs2(pr[0]-65);
		putchar('\n');
	}
	return 0;
}
