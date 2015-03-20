#include <iostream>
#include <math.h>

using namespace std;

bool a[5000000];
int t,n,p[664578],pc=1,low,mid,high;

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

int main(){
    a[0]=0;
    for(int i=1;i<5000000;i++) a[i]=true;
    for(int i=3;i<=sqrt(10000000);i+=2)
        if(a[(i-1)/2])
            for(int j=i*i;j<10000000;j+=i*2)
                a[(j-1)/2]=false;
    p[0]=2;
    for(int i=1;i<5000000;i++)
        if(a[i])
            p[pc++]=i*2+1;
    t=input();
    for(int i=0;i<t;i++)
    {
        n=input();
        if(n==1)
            printf("0\n");
        else{
            low=0;
            high=pc;
            while(high-low>1)
            {
                mid=(low+high)/2;
                if(p[mid]<=n)
                    low=mid;
                else
                    high=mid;
            }
            printf("%d\n",low+1);
        }
    }
    return 0;
}
