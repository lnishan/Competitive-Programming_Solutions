#include<iostream>
using namespace std;
int n,a,b;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            int c=0;
            cin>>a>>b;
            if(a%2==0) a++;
            if(b%2==0) b--;
            for(int j=a;j<=b;j+=2)c+=j;
            cout<<"Case "<<i<<": "<<c<<endl;
    }
    return 0;
}
