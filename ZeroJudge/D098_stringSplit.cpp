#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string s,ts;
int main(){
    while(getline(cin,s))
    {
                         unsigned long int c=0;
                         int n,npos=0;
                         s+=" ";
                         while(npos<s.length())
                         {
                                               ts=s.substr(npos,s.find(" ",npos)-npos);
                                               n=atoi(ts.c_str());
                                               if(n>=pow(10,ts.length()-1))c+=n;
                                               npos=s.find(" ",npos)+1;
                         }
                         cout << c << endl;
    }
    return 0;
}
