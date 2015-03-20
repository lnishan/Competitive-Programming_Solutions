#include<iostream>
#include<string>
using namespace std;
int main(){
    int ds,n,nn,sn,nno[256];
    string let[256],s;
    scanf("%d",&ds);
    for(int i=0;i<ds;i++)
    {
            scanf("%d",&n);
            cin>>sn>>s>>nn;
            for(int j=1;j<n;j++){cin>>sn;cin>>let[sn]>>nno[sn];}
            for(int j=1;j<n;j++)
            {
                    s+=let[nn];
                    nn=nno[nn];
            }
            cout<<s<<endl;
    }
    return 0;
}
