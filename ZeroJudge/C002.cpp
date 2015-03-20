#include<iostream>
using namespace std;
int f[1000001],n;
int main(){
    for(int i=101;i<=1000000;i++) f[i]=i-10;
    for(int i=100;i>0;i--) f[i]=f[f[i+11]];
    while(1)
    {
            cin>>n;
            if(n==0)break;
            cout<<"f91("<<n<<") = "<<f[n]<<endl;
    }
    return 0;
}
    
