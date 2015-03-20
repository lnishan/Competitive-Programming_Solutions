#include <cstdio>

using namespace std;

int n, k, a[100];

void dfs(int s, int ii){
	int i;
	if( ii==k )
	{
		for( i=0; i<k; i++ )
			printf("%d", a[i]);
		putchar('\n');
		return ;
	}
	for( i=s; i<=n; i++ )
	{
		a[ii]=i;
		dfs(i+1, ii+1);
	}
	return ;
}

int main(){
	int t=0;
	//freopen("output.txt", "w", stdout);
	while( scanf("%d%d", &n, &k)==2 )
	{
		printf("case %d:\n", ++t);
		dfs(1, 0);
		if( k>0 ) putchar('\n');
	}
	return 0;
}
