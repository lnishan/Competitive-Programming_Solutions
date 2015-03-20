#include<iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n)
                 cout << ((n<15)?(n+9):(n-15)) << endl;
    return 0;
}
