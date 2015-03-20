/*
ID: linisha1
PROG: ride
LANG: C++
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    string s1,s2;
    long int c1=1,c2=1;
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    fin>>s1>>s2;
    for(int i=0;i<s1.length();i++){c1*=(s1[i]-64);c1%=47;}
    for(int j=0;j<s2.length();j++){c2*=(s2[j]-64);c2%=47;}
    if(c1%47==c2%47)fout<<"GO"<<endl;else fout<<"STAY"<<endl;
    return 0;
}
