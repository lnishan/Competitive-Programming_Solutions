#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    long int n;
    while(cin>>n)
                 cout << fixed << setprecision(3) << (double(n)-32)*5/9 << endl;
    return 0;
}
