#include <iostream>

using namespace std;

int main(){
    int s, t, n, a, sum=0, ans, t1, t2, t3;
    scanf("%d%d%d", &s, &t, &n);
    ans=-s*t*30/100;
    while( n-- )
    {
        scanf("%d", &a);
        sum+=a;
    }
    t1=t/5;
    t2=t*40/100-t1;
    t3=t*60/100-t2-t1;
    if( sum>=t1 ){ ans+=t1*s*70/100; sum-=t1; }else{ ans+=sum*s*70/100; sum=0; }
    if( sum>=t2 ){ ans+=t2*s*80/100; sum-=t2; }else{ ans+=sum*s*80/100; sum=0; }
    if( sum>=t3 ){ ans+=t3*s*90/100; sum-=t3; }else{ ans+=sum*s*90/100; sum=0; }
    ans+=sum*s;
    printf("%d", ans);
    //while(1);
    return 0;
}