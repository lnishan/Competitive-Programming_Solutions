#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double t1,t2,t3,x1,x2;
    while(cin>>t1>>t2>>t3>>x1>>x2)
                                  cout<<fixed<<setprecision(6)<<x1+(t2-t1)*(x1-x2)/(t1-t3)<<endl;
    return 0;
}
