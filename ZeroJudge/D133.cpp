#include<iostream>
using namespace std;
int main(){
    long long int a[30001],mt[5]={1,5,10,25,50},n;
    a[0]=1;
    for(int i=1;i<=30000;i++)a[i]=0;
    for(int i=0;i<5;i++)
            for(int j=mt[i];j<=30000;j++)
                    a[j]+=a[j-mt[i]];
    while(cin>>n)
                              if(a[n]==1)cout<<"There is only "<<a[n]<<" way to produce "<<n<<" cents change."<<endl;
                              else cout<<"There are "<<a[n]<<" ways to produce "<<n<<" cents change."<<endl;
    return 0;
}
