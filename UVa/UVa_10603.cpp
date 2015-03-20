/*
 * PCCA Online
 * submission id: 31248
 * user: linishan
 * status: Accepted
 * runtime: 0.039
 * memory: 
 */#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 202
#define INF 2147483647

using namespace std;

int m[MAX][MAX], w[MAX], tot, cap[3], d;
char inQ[MAX][MAX];
struct state
{
	int a, b;
};
queue<state> q;

inline int input()
{
	char c;
	for( c=getchar(); c<48||c>57; c=getchar() );
	int x=c-48;
	for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
	return x;
}

void pour(state tmp, int s, int e) // pour from s to e
{
	int a[3]={tmp.a, tmp.b, tot-tmp.a-tmp.b}, poured, neww;
	if( a[s]==0 ) return ;
	a[e]+=a[s]; poured=a[s];
	if( a[e] > cap[e] )
	{
		a[s]=a[e]-cap[e];
		poured-=a[s];
		a[e]=cap[e];
	}
	else
		a[s]=0;
	
	neww=m[tmp.a][tmp.b] + poured;
	if( neww < m[a[0]][a[1]] )
	{
		m[a[0]][a[1]]=neww;
		if( !inQ[ a[0] ][ a[1] ] )
		{
			q.push( (state){a[0], a[1]} );
			inQ[ a[0] ][ a[1] ]=1;
		}
	}
	if( neww < w[a[s]] )
		w[a[s]]=neww;
	if( neww < w[a[e]] )
		w[a[e]]=neww;
	
	return ;
}

int main()
{
	memset(inQ, 0, sizeof(inQ));
	int i, j, t;
	state qi;
	t=input();
	while( t-- )
	{
		while( !q.empty() )
		{
			inQ[q.front().a][q.front().b]=0;
			q.pop();
		}
		for( i=0; i<MAX; i++ )
			for( j=0; j<MAX; j++ )
				m[i][j]=INF;
		for( i=0; i<MAX; i++ )
			w[i]=INF;
		//scanf("%d%d%d%d", &cap[0], &cap[1], &cap[2], &d);
		cap[0]=input(); cap[1]=input(); cap[2]=input(); d=input();
		tot=cap[2];
		m[0][0]=0; w[0]=0; w[tot]=0;
		q.push( (state){0, 0} );
		inQ[0][0]=1;
		while( !q.empty() )
		{
			qi=q.front();
			for( i=0; i<3; i++ )
				for( j=i+1; j<3; j++ )
				{
					pour(qi, i, j);
					pour(qi, j, i);
				}
			q.pop();
			inQ[qi.a][qi.b]=0;
		}
		for( i=d; i>=0; i-- )
			if( w[i]!=INF )
				break;
		printf("%d %d\n", w[i], i);
	}
	return 0;
}
