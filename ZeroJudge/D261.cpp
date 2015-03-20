#include<iostream>
int main(){
    long long int n,a,F,M,tF,tM;
    while(scanf("%lld",&n)==1,n>=0)
    {
        F=1;M=0;
        for(a=0;a<n;a++)
        {
            tF=F; tM=M;
            F=tM+1;
            M=M+tF;
        }
        printf("%lld %lld\n",M,F+M);
    }
    return 0;
}
