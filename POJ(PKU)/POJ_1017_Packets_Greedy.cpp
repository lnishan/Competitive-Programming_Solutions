#include <cstdio>

using namespace std;

int gauss(double n)
{
	if (double(int(n)) == n)
		return int(n);
	else
		return int(n) + 1;
}
int a[10];
int u[4] = {0, 5, 3, 1};

int main()
{
	int i, ans, m, l2, l1;
	while ( scanf("%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) && !(a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0) )
	{
		m = a[6] + a[5] + a[4] + gauss(double(a[3]) / 4);
		
		l2 = a[4]*5 + u[ a[3]%4 ]; // a[3] % 4 = the amount of 3x3 packets in the last parcel
		if (a[2] > l2) // need more parcels
			m += gauss(double(a[2] - l2) / 9);
		
		l1 = m*36 - a[6]*36 - a[5]*25 - a[4]*16 - a[3]*9 - a[2]*4;
		if (a[1] > l1)
			m += gauss(double(a[1] - l1) / 36);
		
		printf("%d\n", m);
	}
	return 0;
}
