/*
a b c
d e f
*/

#include <cstdio>

using namespace std;

int main(){
    int a, b, c, d, e, f, dt;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    dt=a*e-b*d;
    if( dt!=0 )
    {
        printf("x=%.2lf\n", double(c*e-b*f)/dt);
        printf("y=%.2lf", double(a*f-c*d)/dt);
    }
    else
    {
        if( c*e-b*f==0 )
            printf("Too many");
        else
            printf("No answer");
    }
    //while(1);
    return 0;
}
