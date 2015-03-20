#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string s;
    stringstream ss;
    long int n, sum;
    while(getline(cin,s))
    {
                         ss.clear();
                         sum=0;
                         ss.str(s);
                         while(ss >> n)
                                  sum+=n;
                         cout << sum << endl;
    }
    return 0;
}
