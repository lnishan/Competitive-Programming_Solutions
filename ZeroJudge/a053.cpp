#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	if( n<=10 )
        printf("%d", n*6);
    else if( n>=11 && n<=20 )
        printf("%d", 60+(n-10)*2);
    else if( n>=21 && n<=40 )
        printf("%d", 80+n-20);
    else
        printf("100");
	return 0;
}
