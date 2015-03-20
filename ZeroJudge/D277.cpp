#include<iostream>
using namespace std;
int main(){
    long int n;
    while(cin>>n) cout << ((n%2==1)?n-1:n) << endl;
    return 0;
}
