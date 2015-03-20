#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int a,b,c,d,d1,d2;
    while(scanf("%d%d%d%d",&a,&b,&c,&d) &&(a!=0||b!=0||c!=0||d!=0))
    {
                                        d1=abs(a-c);
                                        d2=abs(b-d);
                                        if(d1==0&&d2==0)printf("0\n");else if((d1==d2)||(a==c)||(b==d))printf("1\n");else printf("2\n");
    }
    return 0;
}
