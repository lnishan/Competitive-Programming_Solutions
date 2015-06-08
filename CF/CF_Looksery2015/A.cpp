#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char m[52][52];

int main()
{
	int i, j, k, l, ans = 0;
	char v[4];
	int r, c;
	char ch;
	scanf("%d%d", &r, &c);
	for (i = 0; i < r; i++)
	{
		scanf(" ");
		for (j = 0; j < c; j++)
			m[i][j] = getchar();
	}
	for (i = 0; i < r - 1; i++)
		for (j = 0; j < c - 1; j++)
		{
			fill(v, v + 4, 0);
			for (k = 0; k < 2; k++)
				for (l = 0; l < 2; l++)
					if (m[i + k][j + l] == 'f')
						v[0] = 1;
					else if (m[i + k][j + l] == 'a')
						v[1] = 1;
					else if (m[i + k][j + l] == 'c')
						v[2] = 1;
					else if (m[i + k][j + l] == 'e')
						v[3] = 1;
			for (k = 0; k < 4 && v[k]; k++) ;
			ans += k == 4;
		}
	printf("%d\n", ans);
	return 0;
}
