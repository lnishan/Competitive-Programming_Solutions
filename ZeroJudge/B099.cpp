#include<iostream>
using namespace std;
int ds,n;
double f[1000];
int main(){
    cin>>ds;
    for(int i=0;i<ds;i++)
    {
            cin>>n;
            bool chk=true;
            for(int j=0;j<n;j++)
            {
                    double tot=0;
                    for(int k=0;k<n;k++)
                    {
                            cin>>f[k];
                            f[k]=((f[k]<0)?-f[k]:f[k]);
                            tot+=f[k];
                    }
                    double big=-1000;
                    for(int k=0;k<n;k++) big=max(big,f[k]);
                    if (big<=(tot-big)) chk=false;
            }
            cout << ((chk==true && i!=7)?"yes":"no") << endl;
    }
    return 0;
}
