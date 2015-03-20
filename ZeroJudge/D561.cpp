#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;
double abs2(double no);
double abs2(double no){
       return ((no>0)?no:-no);
}
int main(){
    string s;int dpos;double n;
    while(getline(cin,s))
    {
                      dpos=s.find(".");
                      if(s.length()>dpos+3)
                                           s=s.substr(0,dpos+4);
                      n=atof(s.c_str())*100;
                      if(fmod(abs2(n),1)>=0.5)
                                              if(n>0)n+=1;else n-=1;
                      cout<<fixed<<setprecision(2)<<n/100-fmod(n,1)/100<<endl;
    }
    return 0;
}
