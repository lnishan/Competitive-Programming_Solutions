#include<iostream>
using namespace std;
int main(){
    long int n,a[10000];
    long long int c=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                    c+=((a[i]-a[j]<0)?a[j]-a[i]:a[i]-a[j]);
    printf("%lld",c);
    return 0;
}
