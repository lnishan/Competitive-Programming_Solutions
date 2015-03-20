#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int c[91];
char s[12];

int cal(){
    int i, p=0;
    for( i=0; i<8; i++ )
        p+=(s[i]-48)*(8-i);
    return p;
}

int main(){
    c[65]=10;
    c[66]=11;
    c[67]=12;
    c[68]=13;
    c[69]=14;
    c[70]=15;
    c[71]=16;
    c[72]=17;
    c[73]=34;
    c[74]=18;
	c[75]=19;
	c[76]=20;
	c[77]=21;
	c[78]=22;
	c[79]=35;
	c[80]=23;
	c[81]=24;
	c[82]=25;
	c[83]=26;
	c[84]=27;
	c[85]=28;
	c[86]=29;
	c[87]=32;
	c[88]=30;
	c[89]=31;
	c[90]=33;

	int i, t;
	for( i=65; i<=90; i++ )
        c[i]=c[i]/10 + (c[i]%10)*9;
    while( gets(s) )
    {
        t=cal();
        for( i=65; i<=90; i++ )
            if( c[i]+t==s[8]-48 )
                putchar(i);
        putchar('\n');
    }
	return 0;
}
