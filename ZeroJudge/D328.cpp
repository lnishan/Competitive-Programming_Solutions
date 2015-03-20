#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long long int s1,s2,s3;
    while(cin>>s1>>s2>>s3)
                          cout<<fixed<<setprecision(2)<<s1+s2+s3+(double(s2*s3)/double(2*s1))+(double(s3*s1)/double(2*s2))+(double(s1*s2)/double(2*s3))<<endl;
    return 0;
}
