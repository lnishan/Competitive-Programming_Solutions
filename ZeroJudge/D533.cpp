#include<iostream>
using namespace std;
int n;
double a,b,c,d;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>a>>b>>c>>d;
            if(a==c && b==d)
                    cout<<"="<<endl;
            else if(b==0&&d==0)
                  cout<<((a>c)?">":"<")<<endl;
            else
                  cout<<"No"<<endl;
    }
    return 0;
}
