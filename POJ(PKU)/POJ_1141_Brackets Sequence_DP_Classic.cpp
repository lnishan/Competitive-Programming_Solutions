#include <cstdio>
#include <cstring>
#define MAX 105
#define INF 2147483647

using namespace std;

char s[MAX], pre[MAX], post[MAX], mod[MAX];
int dp[MAX][MAX], pos[MAX][MAX];

int dfs(int l, int r)
{
	if (dp[l][r] >= 0)
		return dp[l][r];
	int i, tmp, mlen=INF;
	if (l > r)
		return (dp[l][r] = 0);
	else if (l == r)
	{
		switch (s[l])
		{
			case '(':
				post[l] = ')';
				break;
			case ')':
				pre[l] = '(';
				break;
			case '[':
				post[l] = ']';
				break;
			case ']':
				pre[l] = '[';
				break;
		}
		return (dp[l][r] = 2);
	}
	else
	{
		if ( (s[l] == '(' && s[r] == ')') || (s[l] == '[' && s[r] == ']') )
		{
			mlen = dfs(l+1, r-1) + 2;
			pos[l][r] = 0;
		}
		for (i = l+1; i <= r; i++)
		{
			tmp = dfs(l, i-1) + dfs(i, r);
			if (tmp < mlen)
			{
				mlen = tmp;
				pos[l][r] = i;
			}
		}
		return (dp[l][r] = mlen);
	}
	return 0;
}

void dfs2(int l, int r)
{
	if (l > r)
		return ;
	if (l == r)
	{
		mod[l] = 1;
		return ;
	}
	if (pos[l][r] == 0)
		dfs2(l+1, r-1);
	else
	{
		dfs2(l, pos[l][r]-1);
		dfs2(pos[l][r], r);
	}
}

int main()
{
	int i, j, len;
	
	// init
	for (i = 0; i < MAX; i++)
	{
		mod[i] = 0;
		pre[i] = post[i] = 0;
		for (j = 0; j < MAX; j++)
			dp[i][j] = -1;
	}
	
	// begin
	gets(s);
	len = strlen(s);
	dfs(0, len-1);
	dfs2(0, len-1);
	
	// ans
	for (i = 0; i < len; i++)
	{
		if ( mod[i] && pre[i] > 0)
			putchar(pre[i]);
		putchar(s[i]);
		if ( mod[i] && post[i] > 0)
			putchar(post[i]);
	}
	puts("");
	
	return 0;
}
