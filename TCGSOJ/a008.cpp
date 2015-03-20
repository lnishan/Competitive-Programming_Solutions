#include <iostream>

using namespace std;

int main(){
    double c;
    while( scanf("%lf", &c)==1 )
        printf("%.1lf\n", c*9/5+32);
    return 0;
}
