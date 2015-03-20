#include <cstdio>
#include <cstdlib>

using namespace std;

struct node
{
	char c;
	node *next;
} *first, *iter, *tail, *tmp;

void print()
{
	iter=first;
	while( iter!=NULL )
	{
		putchar(iter->c);
		iter=iter->next;
	}
	putchar('\n');
}

int main()
{
	char c, cmd;
	while( (c=getchar())!=EOF )
	{
		for( ; c!='\n' && (c=='[' || c==']'); c=getchar() );
		if( c=='\n' ){ putchar('\n'); continue; }
		first=(struct node *)malloc(sizeof(struct node));
		first->c = c; first->next=NULL;
		iter=tail=first;
		
		for( c=getchar(); c!='\n' && c!='[' && c!=']'; c=getchar() )
		{
			if( first->next==NULL )
			{
				first->next=(struct node *)malloc(sizeof(struct node));
				iter=first->next;
			}
			else
			{
				iter->next=(struct node*)malloc(sizeof(struct node));
				iter=iter->next;
			}
			iter->c=c;
			iter->next=NULL;
		}
		tail=iter;
		
		do
		{
			for( ; c!='\n' && (c=='[' || c==']'); c=getchar() )
				cmd=c;
			if( c=='\n' ) break;
			iter=(struct node *)malloc(sizeof(struct node));
			iter->c=c;
			iter->next=NULL;
			if( cmd=='[' )
			{
				tmp=first;
				first=iter;
				first->next=NULL;
			}
			else // if( cmd==']' )
				tail->next=iter;
			
			for( c=getchar(); c!='\n' && c!='[' && c!=']'; c=getchar() )
			{
				iter->next=(struct node *)malloc(sizeof(struct node));
				iter=iter->next;
				iter->c=c;
				iter->next=NULL;
			}
			
			if( cmd=='[' )
				iter->next=tmp;
			else // if( cmd==']' )
			{
				while( tail->next!=NULL )
					tail=tail->next;
			}
			
		}while( c!='\n' );
		print();
	}
	return 0;
}
