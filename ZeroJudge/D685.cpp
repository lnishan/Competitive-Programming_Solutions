#include <iostream>

using namespace std;

long long int a,b,c,d,e,f;

int main(){
    while(scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f)==6)
    {
        if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0) break;
        if(a*e==b*d){
            if(a*f==c*d)
                printf("\"A lot of answer\"");  //s?
            else
                printf("\"no answer\"");
        }else
            printf("\"x=%lld , y=%lld\"",(c*e-b*f)/(a*e-b*d),(a*f-c*d)/(a*e-b*d));
        putchar('\n');
    }
    return 0;
}
