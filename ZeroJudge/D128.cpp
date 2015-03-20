#include<iostream>
using namespace std;
int a,b,c,ans;
int main(){
    while(cin>>a>>b>>c)
    {
                       ans=-1;
                       int ar[8]={a+b+c,a*b+c,a+b*c,a*b*c,(10*a+b)+c,(10*a+b)*c,a+(10*b+c),a*(10*b+c)};
                       for(int i=0;i<8;i++)ans=max(ar[i],ans);
                       cout<<ans<<endl;
    }
    return 0;
}
