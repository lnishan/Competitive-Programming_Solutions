#include <iostream>

using namespace std;

int main(){
    int i, j, n;
    double R, G, B, Yc=0;
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        for( j=0; j<n; j++ )
        {
            scanf("%lf%lf%lf", &R, &G, &B);
            printf("%.4lf %.4lf %.4lf\n", 0.5149*R+0.3244*G+0.1607*B, 0.2654*R+0.6704*G+0.0642*B, 0.0248*R+0.1248*G+0.8504*B);
            Yc+=0.2654*R+0.6704*G+0.0642*B;
        }
    printf("The average of Y is %.4lf", Yc/(n*n));
    //while(1);
    return 0;
}