#include <iostream>

using namespace std;

int n,low,mid,high,cpos,tmp;
long long int cost,a[5000];

int input(){
    char c;
    for(c=getchar();c<48||c>57;c=getchar());
    int x=c-48;
    for(c=getchar();c>47&&c<58;c=getchar()) x=x*10+c-48;
    return x;
}

void bSearch(long long int no){
    low=cpos+1; high=n;
    while(high-low>1)
    {
        mid=(low+high)/2;
        if(a[mid]<=no)
            low=mid;
        else
            high=mid;
    }
}

int main(){
    while(scanf("%d",&n),n!=0)
    {
        for(int i=0;i<n;i++) a[i]=input();
        sort(a,a+n);
        cost=cpos=0;
        for(int i=1;i<n;i++,cpos++)
        {
            tmp=a[cpos]+a[cpos+1];
            cost+=tmp;
            a[cpos]=100000;
            bSearch(tmp);
            for(int j=cpos+1;j<low;j++)
                a[j]=a[j+1];
            a[low]=tmp;
        }
        printf("%lld\n",cost);
    }
    return 0;
}
