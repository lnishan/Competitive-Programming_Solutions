#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cout<<"PERFECTION OUTPUT"<<endl;
    while(cin>>n)
    {
                 int c=1;
                 if(n==0)
                 {
                         cout<<"END OF OUTPUT";
                         break;
                 }else
                 {
                      for(int i=2;i<=sqrt(n);i++)
                              if(n%i==0)c+=((n==i*i)?i:i+n/i);
                      if(n==c&&n!=1)cout<<n<<"  "<<"PERFECT"<<endl; else if(c<n||n==1) cout<<n<<"  "<<"DEFICIENT"<<endl; else cout<<n<<"  "<<"ABUNDANT"<<endl;
                 }
    }
    return 0;
}
