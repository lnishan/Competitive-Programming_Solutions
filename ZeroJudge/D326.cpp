#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
long long int t[33];
long long int check_bit(long long int v,long long int a,long long int b);
long long int set_bit(int v, int b)
{
 if(!check_bit(v,32,b))return v+t[b];else return v;
}
/* set bit b to 0 */
long long int unset_bit(long long int v,long long int b)
{
 if(check_bit(v,32,b))return v-t[b];else return v;
}
/* check_bit b is 1 or 0 */
long long int check_bit(long long int v,long long int a,long long int b)
{
 return (v>>b)%2;
}
int main()
{
    t[0]=1;
    for(int i=1;i<33;i++)t[i]=t[i-1]*2;
    long long int i, v, bit, isSet;
    while(scanf("%lld %lld %lld",&v,&bit,&isSet)==3)
    {
        if(isSet)
            v = set_bit(v, bit);
        else
            v = unset_bit(v, bit);
        for(i=31;i>=0;--i)
            printf("%d",abs(check_bit(v, 32, i)));
        putchar('\n');
    }
    return 0;
}
