#include <cstdio>

using namespace std;

int main()
{
	int h, m;
	double angle;
	while( scanf("%d:%d", &h, &m)==2 && !(h==0 && m==0) )
	{
		angle=(30*h+double(m)/60*30) - m*6;
		if( angle<0 ) angle=-angle;
		if( angle>180 ) angle=360-angle;
		printf("%.3lf\n", angle);
	}
	return 0;
}
