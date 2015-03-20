#include <iostream>

using namespace std;

int t;
double nx1,ny1,nx2,ny2,a,b;

int main(){
    while(scanf("%d",&t)==1 && t>0 && !feof(stdin))
    {
        for(int d=0;d<t;d++)
        {
            scanf("\nf(%lf)=%lf",&nx1,&ny1);
            if(feof(stdin)) break;
            scanf("\nf(%lf)=%lf",&nx2,&ny2);
            a=(ny2-ny1)/(nx2-nx1);
            b=(nx1*ny2-nx2*ny1)/(nx1-nx2);
            printf("\"f(x)=");
            if(a==-1) putchar('-');
            if(a!=1 && a!=-1) printf("%.0lf",a);
            if(a!=0) putchar('x');
            if(b!=0){
                if(b>0) putchar('+');
                printf("%.0lf",b);
            }
            putchar('\"');
            putchar('\n');
        }
    }
    return 0;
}
