#include <cstdio>
#include <queue>

using namespace std;

int cnt[20]={0};
queue<int> q[20];
queue<int> ans;

void init(int lmt)
{
	int i, t, ct;
	for( i=1; i<=lmt; i++ )
	{
		t=i; ct=0;
		while( t>0 )
		{
			if( t%2==1 )
				break;
			else
				t>>=1;
			ct++;
		}
		cnt[ct]++;
		q[ct].push(i);
	}
	return ;
}

int main()
{
	int i, s, l, tmp;
	scanf("%d%d", &s, &l);
	init(l);
	for( i=19; i>=0; i-- )
	{
		tmp=1<<i;
		while( cnt[i]>0 && s>=tmp )
		{
			s-=tmp;
			cnt[i]--;
			ans.push(q[i].front());
			q[i].pop();
		}
	}
	if( s==0 )
	{
		printf("%d\n", ans.size());
		printf("%d", ans.front()); ans.pop();
		while( !ans.empty() )
		{
			printf(" %d", ans.front());
			ans.pop();
		}
	}
	else
		printf("-1");
	return 0;
}
