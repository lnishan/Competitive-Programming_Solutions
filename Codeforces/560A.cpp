#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char one = 0;
	int n, ai;
	scanf("%d", &n);
	while (n--) { scanf("%d", &ai); if (ai == 1) one = 1; }
	puts(one ? "-1" : "1");
	return 0;
}