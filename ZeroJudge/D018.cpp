#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string s,ts;
int a,ppos;
double b,oddc,evenc;
int main(){
    while(getline(cin,s))
    {
           s+=" ";
           int npos=0; oddc=0; evenc=0;
           while(npos<s.length())
           {
                                    ts=s.substr(npos,s.find(" ",npos)-npos);
                                    ppos=ts.find(":");
                                    a=atoi(ts.substr(0,ppos).c_str());
                                    b=atof(ts.substr(ppos+1,ts.length()-ppos-1).c_str());
                                    if(a%2==1) oddc+=b; else evenc+=b;
                                    npos=s.find(" ",npos)+1;
           }
           cout << oddc-evenc << endl;
    }
    return 0;
}
