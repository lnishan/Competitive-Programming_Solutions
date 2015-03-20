#include <cstdio>

using namespace std;

int m[4][4], path[100], mx[4]={1, 0, 0, -1}, my[4]={0, 1, -1, 0}, cx[20], cy[20];
char cmd[4]={'D', 'R', 'L', 'U'};
inline void iswap(int &a, int &b){ int tmp=a; a=b; b=tmp; }
inline int iabs(int n){ return n>0?n:-n; }
inline int input()
{
	char c;
	for( c=getchar(); c<48||c>57; c=getchar() );
	int x=c-48;
	for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
	return x;
}

void pre()
{
	int i, j, cnt;
	for( cnt=1, i=0, j=0; i<4 ; cnt++ )
	{
		cx[cnt]=i;
		cy[cnt]=j;
		if( j>=3 )
			j=0, i++;
		else
			j++;
	}
	return ;
}

bool solvable()
{
	int i, j, k, l;
	int cnt=0;
	for( i=0; i<4; i++ )
		for( j=0; j<4; j++ )
			if( m[i][j]!=0 )
				for( k=i, l=j; k>=0 && l>=0; )
				{
					if( m[k][l] > m[i][j] )
						cnt++;
					if( l>0 )
						l--;
					else
						l=3, k--;
				}
			else
				cnt+=(i+1); // Zero located at (i+1)th row
	return ( cnt%2==0 );
}

int calH()
{
	int i, j, h=0;
	for( i=0; i<4; i++ )
		for( j=0; j<4; j++ )
			if( m[i][j]>0 )
				h+= iabs( cx[m[i][j]] - i ) + iabs( cy[m[i][j]] - j );
	return h;
}

bool DFS_ID(int lmt, int px, int py, int zx, int zy, int g, int h, int pi)
{
	int i, j, nx, ny;
	h+= iabs( cx[m[px][py]] - px ) + iabs( cy[m[px][py]] - py ) - iabs( cx[m[px][py]] - zx ) - iabs( cy[m[px][py]] - zy );
	if( g+h > lmt )
		return false;
	if( h==0 )
		return true;
	for( i=0; i<4; i++ )
		if( pi+i!=3 )
		{
			nx=zx+mx[i];
			ny=zy+my[i];
			if( nx>=0 && nx<4 && ny>=0 && ny<4 )
			{
				path[g+1]=i;
				iswap(m[zx][zy], m[nx][ny]);
				if( DFS_ID(lmt, zx, zy, nx, ny, g+1, h, i) )
					return true;
				iswap(m[zx][zy], m[nx][ny]);
			}
		}
	return false;
}

int main()
{
	int i, j, t, stp, zx, zy, h;
	pre();
	t=input();
	while( t-- )
	{
		for( i=0; i<4; i++ )
			for( j=0; j<4; j++ )
			{
				m[i][j]=input();
				if( m[i][j]==0 )
				{
					zx=i;
					zy=j;
				}
			}
		if( solvable() )
		{
			h=calH();
			stp=h-1;
			while( !DFS_ID(++stp, zx, zy, zx, zy, 0, h, 10000) );
			
			for( i=1; i<=stp; i++ )
				putchar(cmd[ path[i] ]);
			putchar('\n');
		}
		else
			puts("This puzzle is not solvable.");
	}
	return 0;
}
