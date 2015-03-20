#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int a, b;
int main(){
    cin>>a>>b;
    cout<<pow(a,b)<<endl;
    cin>>a;
    cout<<fixed<<setprecision(3)<<sqrt(a)<<endl;
    cin>>a;
    cout<<abs(a)<<endl;
    cin>>a>>b;
    cout<<(a+b)/2;
    return 0;
}
