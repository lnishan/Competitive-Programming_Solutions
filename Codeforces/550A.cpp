#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];

int main()
{
	int i, j, k, l;
	gets(s);
	l = strlen(s);
	for (i = 0, k = 0; i < 3; i++)
	{
		for (j = k; j < l - 1; j++)
			if (s[j] == 'A' && s[j + 1] == 'B')
			{
				s[j] = s[j + 1] = -1;
				k = j + 1;
				break;
			}
		if (j < l - 1)
		{
			for (j = 0; j < l - 1; j++)
				if (s[j] == 'B' && s[j + 1] == 'A')
					break;
			if (j < l - 1) break;
			s[k - 1] = 'A';
			s[k] = 'B';
		}
	}
	if (i < 3)
		puts("YES");
	else
		puts("NO");
	return 0;
}