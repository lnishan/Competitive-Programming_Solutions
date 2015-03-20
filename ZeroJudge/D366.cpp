#include<iostream>

using namespace std;

char ar[31624];

int p[3401],n,a,b,mdiv,mn,tct,tmp,pct=0,ti;

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar()) ;
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    int d,i,j;
    ar[2]=1;
    for(i=3;i<31624;i+=2) ar[i]=1;
    for(i=4;i<31624;i+=2) ar[i]=0;
    for(i=3;i<178;i+=2)
        if(ar[i])
            for(j=i*i;j<31624;j+=i<<1)
                ar[j]=0;
    for(int i=2;i<31624;i++)
        if(ar[i])
            p[pct++]=i;
    n=input();
    for(d=0;d<n;d++)
    {
        mdiv=0;
        a=input();
        b=input();
        for(i=a;i<=b;i++)
        {
            tct=1; ti=i;
            for(int j=0;j<pct;j++)
            {
                if(p[j]*p[j]>ti) break;
                tmp=1;
                if(ti%p[j]==0)
                    while(ti%p[j]==0)
                    {
                        ti/=p[j];
                        tmp++;
                    }
                tct*=tmp;
            }
            if(ti>1) tct*=2;
            if(tct>mdiv){mdiv=tct; mn=i;}
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",a,b,mn,mdiv);
    }
    return 0;
}