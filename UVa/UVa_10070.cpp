#include <cstdio>
#include <cstring>

using namespace std;

char yr[10002];

int main(){
	int i, l, oddct, evenct;
	char c1, c2, c3, f=1;
	
	while( gets(yr) )
	{
		if( !f )
			putchar('\n');
		else
			f=0;
    	
		l=strlen(yr);
		c1=c2=c3=1;
		
		if(  (((yr[l-2]-48)*10+yr[l-1]-48)%4==0 && !(yr[l-2]==48 && yr[l-1]==48)) || ( (yr[l-2]==48&&yr[l-1]==48) && ((yr[l-4]-48)*10+yr[l-3]-48)%4==0 )   )
			puts("This is leap year.");
		else
			c1=0;
		
		oddct=evenct=0;
		for( i=0; i<l; i++)
			if( i%2 )
				oddct+=yr[i]-48;
			else
				evenct+=yr[i]-48;
		
		if( (oddct+evenct)%3==0 && (yr[l-1]==53||yr[l-1]==48) )
			puts("This is huluculu festival year.");
		else
			c2=0;
		
		if( (oddct-evenct)%11==0 && (yr[l-1]==53||yr[l-1]==48) && c1 )
			puts("This is bulukulu festival year.");
		else
			c3=0;
			
		if( !c1 && !c2 && !c3 )
			puts("This is an ordinary year.");
    }
    return 0;
}

