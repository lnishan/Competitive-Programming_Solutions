#include<iostream>
using namespace std;
unsigned long long int n;
int main(){
    while(cin>>n)
    cout<<(((n/2)%2==1)?(n/2/2)*(n/2/2+1):(n/2/2)*(n/2/2))<<endl;
    return 0;
}
