#include <cstdio>

using namespace std;

int a[100];
int main(){
	int i, n;
	a[1]=1;
	for( i=2; i<=100; i++ )
		a[i]=a[i-1]+i*i;
	while( scanf("%d", &n)==1 && n>0 )
		printf("%d\n", a[n]);
	return 0;
}
