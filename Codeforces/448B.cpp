#include <cstdio>
#include <cstring>
#define MAX 30
#define LEN 105

int cnt1[MAX], cnt2[MAX];
char s1[LEN], s2[LEN];

int main()
{
	int i, j, l1, l2;
	gets(s1);
	l1=strlen(s1);
	for (i = 0; i < l1; i++)
		cnt1[s1[i]-'a']++;
	
	gets(s2);
	l2=strlen(s2);
	for (i = 0; i < l2; i++)
		cnt2[s2[i]-'a']++;
	
	for (i = 0; i < 26; i++)
		if (cnt2[i] > cnt1[i])
		{
			puts("need tree");
			break;
		}
	if (i == 26)
	{
		if (l1 > l2)
		{
			for (i = 0, j = 0; i < l1 && j < l2; )
				if (s1[i] == s2[j])
				{
					i++;
					j++;
				}
				else
					i++;
			if (j == l2)
				puts("automaton");
			else
				puts("both");
		}
		else
			puts("array");
	}
	return 0;
}
