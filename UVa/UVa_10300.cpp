#include<iostream>
using namespace std;
int ds, frs;
int main(){
    cin>>ds;
    for(int i=0;i<ds;i++)
    {
            cin>>frs;
            unsigned long long int a,b,c,ans=0;
            for(int j=0;j<frs;j++){cin>>a>>b>>c; ans+=a*c;}
            cout << ans << endl;
    }
    return 0;
}
