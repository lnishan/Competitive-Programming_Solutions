#include <cstdio>
#include <cstring>

using namespace std;

int k[25][26], p[25][2];
char s[20], c1[5], c2[5];

void ret(int i)
{
	int j, n;
	for( j=p[i][1]+1; j<=k[p[i][0]][0]; j++ )
	{
		n=k[p[i][0]][j];
		
		p[n][0]=n;
		p[n][1]=1;
		k[n][0]=1;
		k[n][1]=n;
	}
	k[p[i][0]][0]=p[i][1];
}

void move(int a, int b)
{
	int j, n, y, tmpx=p[a][0], tmpy=p[a][1], diff=k[p[a][0]][0]-p[a][1]+1;
	for( j=tmpy; j<=k[tmpx][0]; j++ )
	{
		n=k[tmpx][j];
		y=k[p[b][0]][0]+j-tmpy+1;
		
		p[n][0]=p[b][0];
		p[n][1]=y;
		k[p[b][0]][y]=n;
	}
	k[p[b][0]][0]+=diff;
	k[tmpx][0]-=diff;
}

int main()
{
	int i, j, n, a, b;
	scanf("%d", &n);
	for( i=0; i<n; i++ )
	{
		p[i][0]=i;
		p[i][1]=1;
		
		k[i][0]=1;	// size
		k[i][1]=i;
	}
	
	scanf("\n");
	while( gets(s) && s[0]!='q' )
	{
		sscanf(s, "%s %d %s %d", &c1, &a, &c2, &b);
		if( p[a][0]!=p[b][0] )
		{
			if( strcmp(c1, "move")==0 )
			{
				if( strcmp(c2, "onto")==0 )
				{
					ret(a);
					ret(b);
					move(a, b);
				}
				else if( strcmp(c2, "over")==0 )
				{
					ret(a);
					move(a, b);
				}
			}
			else if( strcmp(c1, "pile")==0 )
			{
				if( strcmp(c2, "onto")==0 )
				{
					ret(b);
					move(a, b);
				}
				else if( strcmp(c2, "over")==0 )
				{
					move(a, b);
				}
			}
		}
	}
	for( i=0; i<n; i++ )
	{
		printf("%d:", i);
		for( j=1; j<=k[i][0]; j++ )
			printf(" %d", k[i][j]);
		putchar('\n');
	}
	return 0;
}
