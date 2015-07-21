#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

char sc[130];
char s[10];

int main()
{
	memset(sc, 0, sizeof(sc));
	sc['Q'] = 9;
	sc['R'] = 5;
	sc['B'] = sc['N'] = 3;
	sc['P'] = 1;
	sc['K'] = 0;
	int i, j, k, l, fsc[2] = {0, 0};
	for (i = 0; i < 8; i++)
	{
		gets(s);
		l = strlen(s);
		for (j = 0; j < l; j++)
				fsc[ (bool)islower(s[j]) ] += sc[toupper(s[j])];
	}
	//printf("%d %d\n", fsc[0], fsc[1]);
	if (fsc[0] == fsc[1])
		puts("Draw");
	else if (fsc[0] > fsc[1])
		puts("White");
	else
		puts("Black");
	return 0;
}
