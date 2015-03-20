#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long long int n;
    bool m;
    while(cin>>n)
    {
                 
                 long long int c;
                 if(n<0){m=true; n=-n;}else{m=false;}
                 for(int i=sqrt(n);i>=1;i--)
                 {
                         if(n%(i*i)==0){c=i;break;}
                 }
                 if(c!=1&&n!=0)cout<<c;
                 if(n/(c*c)!=1 && n!=0)cout<<"_/"<<n/(c*c);
                 if(n==1||n==0)cout<<n;
                 if(m==true)cout<<"i";
                 cout<<endl;
    }
    return 0;
}
