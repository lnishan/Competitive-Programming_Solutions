#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;
int main(){
    int a[100],n,m;
    freopen("D6xx.in","w",stdout);
    srand(time(NULL));
    for(int i=0;i<6;i++)
    {
        n=(rand()%30)+1;
        do
            m=(rand()%30)+1;
        while((n-m)>5 || m>n);
        printf("%d %d\n",n,m);
        for(int j=0;j<n;j++){if(j>0)putchar(' ');printf("%d",(rand()%2000000000)+1);}
        putchar('\n');
    }
    for(int i=0;i<20;i++) a[i]=4; a[20]=2;
    for(int i=21;i<40;i++) a[i]=3;
    a[40]=2;
    a[41]=999;
    a[42]=9999;
    a[43]=2147483647;
    a[44]=3;
    a[45]=66;
    a[46]=a[47]=4;
    for(int i=48;i<60;i++) a[i]=44444444;
    for(int i=60;i<70;i++) a[i]=44444445;
    a[70]=999;
    a[71]=1000;
    for(int i=72;i<100;i++) a[i]=20;
    for(int i=0;i<100;i+=96)
    {
        printf("100 %d\n",i+1);
        for(int j=0;j<100;j++){if(j>0)putchar(' '); printf("%d",a[j]);}
        putchar('\n');
    }
    printf("0 0");
    return 0;
}
