#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>

using namespace std;

long long int stk[300000];
int stk2[300000];
char s[500000], *ptr;

int main()
{
	int i, l, top;
	long long int a, b, c;
	bool legal, ad;
	while( gets(s) )
	{
		legal=true;
		top=-1;
		if( strlen(s)==1 && s[0]=='.' ) break;
		ptr=strtok(s, " ");
		while( ptr!=NULL )
		{
			if( strlen(ptr)>0 )
			{
				l=strlen(ptr);
				ad=true;
				for( i=0; i<l; i++ )
					if( !isdigit(ptr[i]) )
					{
						ad=false;
						break;
					}
				if( !ad && l>1 )
				{
					legal=false;
					break;
				}
				if( isdigit(ptr[0]) )
				{
					stk[++top]=ptr[0]-48;
					stk2[top]=0;
					for( i=1; i<l; i++ )
						stk[top]=stk[top]*10+ptr[i]-48;
					if( stk[top]<=0 )
					{
						legal=false;
						break;
					}
				}
				else
				{
					stk[++top]=ptr[0];
					stk2[top]=1;
				}
				while( top>=2 )
				{
					if( stk2[top]==0 && stk2[top-1]==0 )
					{
						b=stk[top];
						a=stk[top-1];
						if( stk2[top-2]!=1 )
						{
							legal=false;
							break;
						}
						else
						{
							switch(stk[top-2])
							{
								case '+':
									c=a+b;
									break;
								case '-':
									c=a-b;
									break;
								case '*':
									c=a*b;
									break;
								case '/':
									c=a/b;
									break;
								case '%':
									c=a%b;
							}
						}
						top-=3;
						stk[++top]=c;
						stk2[top]=0;
					}
					else
						break;
				}
				if( !legal ) break;
			}
			ptr=strtok(NULL, " ");
		}
		if( top>0 || (top==0 && stk2[0]==1) || top<0 ) legal=false;
		if( legal )
			printf("%lld\n", stk[0]);
		else
			puts("illegal");
	}
	return 0;
}
