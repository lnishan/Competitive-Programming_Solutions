#include<iostream>
using namespace std;
int n,a[50002],d;
int main(){
    while(scanf("%d",&n)&&n!=0)
    {
         for(int i=0;i<n;i++)scanf("%d",&a[i]);
         sort(a,a+n);
         d=a[1]-a[0];
         bool chk=true;
         for(int i=2;i<n;i++)
                 if(a[i]-a[i-1]!=d){chk=false;break;}
         printf((chk)?"Yes\n":"No\n");
    }
    return 0;
}
