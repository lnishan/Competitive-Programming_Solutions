#include<iostream>
using namespace std;
int ds,a,b;
int main(){
    cin>>ds;
    for(int i=0;i<ds;i++)
    {
            cin>>a>>b;
            for(int j=0;j<b;j++)
            {
                    for(int k=1;k<=a;k++)
                    {
                            for(int l=0;l<k;l++)cout<<k;
                            cout<<endl;
                    }
                    for(int k=a-1;k>=1;k--)
                    {
                            for(int l=0;l<k;l++)cout<<k;
                            cout<<endl;
                    }
                    cout<<endl;
            }
    }
    return 0;
}
