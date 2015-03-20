#include <cstdio>
#include <cstring>

using namespace std;

char a[2200][2200];
int pow3[8] = {1, 3, 9, 27, 81, 243, 729, 2187};


int main()
{
	int i, j, k, w, n;
	
	// init
	memset(a, 0, sizeof(a));
	a[0][0] = 1;
	
	// start
	for (k = 0; k < 7; k++)
	{
		// copying 3^k * 3^k
		w = pow3[k];
		for (i = 0; i < w; i++)
			for (j = 0; j < w; j++)
				a[0 + i][w*2 + j] = 
				a[w + i][w + j] = 
				a[w*2 + i][0 + j] = 
				a[w*2 + i][w*2 + j] = a[i][j];
	}
	
	while (scanf("%d", &n) == 1 && n != -1)
	{
		w = pow3[n-1];
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < w; j++)
				putchar( a[i][j] ? 'X' : ' ' );
			puts("");
		}
		puts("-");
	}
	return 0;
}
