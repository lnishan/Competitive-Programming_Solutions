#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double a,b,c,d;
    while(scanf("%lf%lf%lf%lf",&a,&b,&c,&d)!=EOF) printf("%d\n",int(ceil((a+b*8+c*27+d*64)/64)));
    return 0;
}
