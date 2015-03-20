/* Flatten the tree => put all left childs on the left of the root
The number of nodes in a subtree is its leftmost child to its root*/

#include <cstdio>
#include <vector>
#define MAX 100002

using namespace std;

struct node_lis
{
	int n;
	node_lis *next;
	node_lis(int n, node_lis *next=NULL): n(n), next(next){}
};
class lis
{
public:
	node_lis *first, *cur;
	lis(): first(NULL), cur(){}
	void insert(int n)
	{
		if( first==NULL )
		{
			first=new node_lis(n);
			cur=first;
		}
		else
		{
			cur->next=new node_lis(n);
			cur=cur->next;
		}
		return ;
	}
};
struct node
{
	int leftMost;
	int finTime;
} tree[MAX];

inline int input()
{
	char c;
	for( c=getchar(); c<48||c>57; c=getchar() );
	int x=c-48;
	for( c=getchar(); c>47&&c<58; c=getchar() ) x=x*10+c-48;
	return x;
}

int arr[MAX], fenwick[MAX], maxIdx, time;
lis g[MAX];
char vst[MAX];

int query(int idx)
{
	if( idx==0 )
		return 0;
	int sum=0;
	while( idx>0 )
	{
		sum+=fenwick[idx];
		idx -= idx & (-idx);
	}
	return sum;
}

void update(int idx, int n)
{
	while( idx<=maxIdx )
	{
		fenwick[idx]+=n;
		idx += idx & (-idx);
	}
	return ;
}

int buildTree(int idx)
{
	int childCnt=0, ret;
	node_lis *i=g[idx].first;
	while( i!=NULL )
	{
		int &v=(*i).n;
		if( !vst[ v ] )
		{
			vst[v]=1;
			childCnt++;
			ret=buildTree( v );
			if( childCnt==1 )
				tree[idx].leftMost=ret;
		}
		i=i->next;
	}
	if( childCnt==0 )
		tree[idx].leftMost=idx;
	tree[idx].finTime=time++;
	return tree[idx].leftMost;
}

int main()
{
	int i, j, n, m, a, b;
	char c;
	time=1;
	
	n=input(); maxIdx=n;
	
	for( i=1; i<=n; i++ )
	{
		arr[i]=1;
		fenwick[i]=0;
		vst[i]=0;
	}
	for( i=1; i<=n; i++ )
		update(i, +1);
	
	for( i=1; i<n; i++ )
	{
		a=input(); b=input();
		g[a].insert(b);
		g[b].insert(a);
	}
	
	vst[1]=1;
	buildTree(1);
	
	m=input();
	while( m-- )
	{
		scanf(" %c %d", &c, &a);
		if( c=='Q' )
			printf("%d\n", query(tree[a].finTime) - query( tree[ tree[a].leftMost ].finTime -1 ) );
		else // C
		{
			if( arr[a]==1 )
				update( tree[a].finTime, -1 );
			else
				update( tree[a].finTime, +1 );
			arr[a]=1-arr[a];
		}
	}
	
	return 0;
}
