#include <cstdio>
#include <cstring>
#include <cctype>
#define SBL 102
#define LEN 10002

using namespace std;

char stkSbl[SBL]; int topSbl;
char stkOpr[SBL]; int topOpr;
char s[LEN];
int pri[128];

void setPri()
{
	pri['('] = 0;
	pri['|'] = 1;
	pri['&'] = 2;
	pri['!'] = 3;
}

void eval()
{
	switch (stkOpr[topOpr])
	{
		case '!':
			stkSbl[topSbl] ^= 1;
			break;
		case '&':
			stkSbl[topSbl-1] = stkSbl[topSbl-1] & stkSbl[topSbl];
			--topSbl;
			break;
		case '|':
			stkSbl[topSbl-1] = stkSbl[topSbl-1] | stkSbl[topSbl];
			--topSbl;
			break;
	}
	--topOpr;
}

int main()
{
	int i, j, l, cases = 0;
	setPri();
	while (gets(s))
	{
		topSbl = topOpr = -1;
		l = strlen(s);
		for (i = 0; i < l; i++)
		{
			if (s[i] == ' ') continue;
			if (isalpha(s[i]))
				stkSbl[++topSbl] = s[i] == 'V' ? 1 : 0;
			else
			{
				char &opr = s[i];
				if (opr == '(')
					stkOpr[++topOpr] = opr;
				else if (opr == ')')
				{
					while (stkOpr[topOpr] != '(')
						eval();
					--topOpr;
				}
				else
				{
					while (topOpr >= 0 && pri[stkOpr[topOpr]] > pri[opr])
						eval();
					stkOpr[++topOpr] = opr;
				}
			}
		}
		while (topOpr >= 0)
			eval();
		printf("Expression %d: %c\n", ++cases, stkSbl[0] ? 'V' : 'F');
	}
	return 0;
}
