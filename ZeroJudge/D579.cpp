#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double n;
    while(cin>>n) cout<<fixed<<setprecision(4)<<"|"<<n<<"|="<<((n>0)?n:-n)<<endl;
    return 0;
}
