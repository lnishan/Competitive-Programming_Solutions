#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int det[130], light[130], heavy[130];

int main()
{
	int i, j, t, imb_cnt;
	string s1, s2, verd;
	cin >> t;
	while (t--)
	{
		imb_cnt = 0;
		for (i = 'A'; i <= 'L'; i++) det[i] = light[i] = heavy[i] = 0;
		for (i = 0; i < 3; i++)
		{
			cin >> s1 >> s2 >> verd;
			const int &len = s1.length();
			if (verd == "even")
			{
				
				for (j = 0; j < len; j++)
					det[s1[j]] = det[s2[j]] = 1;
			}
			else
			{
				imb_cnt++;
				if (verd == "up") swap(s1, s2);
				for (j = 0; j < len; j++)
				{
					light[s1[j]]++;
					heavy[s2[j]]++;
				}
			}
		}
		for (i = 'A'; i <= 'L'; i++)
		{
			if (det[i]) continue;
			if (light[i] == imb_cnt)
			{
				printf("%c is the counterfeit coin and it is light.\n", i);
				break;
			}
			else if (heavy[i] == imb_cnt)
			{
				printf("%c is the counterfeit coin and it is heavy.\n", i);
				break;
			}
		}
	}
	return 0;
}
