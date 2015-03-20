#include<iostream>
using namespace std;
int main(){
    unsigned long long int a,b;
    while(cin>>a>>b && (a!=0 || b!=0)) cout << ((a<=b)?"Fair":"Unfair") << endl;
    return 0;
}
