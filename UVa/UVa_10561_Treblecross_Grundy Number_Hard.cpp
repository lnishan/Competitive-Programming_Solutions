#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 205

using namespace std;

int g[MAX];
char s[MAX];
int mtry[5] = {-2, -1, 0, 1, 2};
char avail[MAX];
vector<int> vAns;

inline bool valid(const int &n, const int &sz)
{
	return n >= 0 && n < sz;
}

int calGrundy(int, int);
int grundy(int n)
{
	int &cur = g[n];
	if (cur!= -1) return cur;
	int i, ret;
	char used[MAX];
	memset(used, 0, sizeof(used));
	for (i = 0; i < n; i++)
		used[ calGrundy(n, i) ] = 1;
	for (i = 0; i < MAX; i++)
		if (!used[i])
			return cur = i;
}

int calGrundy(int len, int pos)
{
	int i, j, ret = 0;
	if (pos - 3 >= 0)
		ret = grundy(pos - 3 + 1);
	if (pos + 3 < len)
		ret ^= grundy(len - (pos + 3));
	return ret;
}

int getGrundy(char s[], const int &l)
{
	int i, j, ret = 0;
	char *avail = new char[l];
	for (i = 0; i < l; i++) avail[i] = 1;
	for (i = 0; i < l; i++)
		if (s[i] == 'X')
			for (j = 0; j < 5; j++)
				if (valid(i + mtry[j], l))
					avail[i + mtry[j]] = 0;
	for (i = 0; i < l; i++)
		if (avail[i])
		{
			for (j = i+1; j < l && avail[j]; j++) ;
			ret ^= grundy(j - i);
			i = j-1;
		}
	delete [] avail;
	return ret;
}

int count(char s[], const int &l, int idx)
{
	int i, ret = 1;
	for (i = idx+1; i < l && s[i] == 'X'; i++)
		ret++;
	for (i = idx-1; i >= 0 && s[i] == 'X'; i--)
		ret++;
	return ret;
}

int main()
{
	int i, j, t, l, grd;
	memset(g, -1, sizeof(g));
	scanf("%d ", &t);
	while (t--)
	{
		vAns.clear();
		grd = -1;
		gets(s);
		l = strlen(s);
		for (i = 0; i < l; i++) avail[i] = 1;
		for (i = 0; i < l; i++)
			if (s[i] == 'X')
				for (j = 0; j < 5; j++)
					if (valid(i + mtry[j], l))
						avail[i + mtry[j]] = 0;
		for (i = 0; i < l; i++)
			if (s[i] == '.')
				if (count(s, l, i) >= 3)
					vAns.push_back(i+1);
		if (vAns.size() == 0)
		{
			for (i = 0; i < l; i++)
				if (avail[i])
				{
					s[i] = 'X';
					if (getGrundy(s, l) == 0)
						vAns.push_back(i+1);
					s[i] = '.';
				}
		}
		if (vAns.size() == 0)
			puts("LOSING");
		else
		{
			puts("WINNING");
			for (i = 0; i < vAns.size(); i++)
			{
				if (i > 0) putchar(' ');
				printf("%d", vAns[i]);
			}
		}
		puts("");
	}
	return 0;
}
