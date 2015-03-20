#include<iostream>
#include<math.h>
using namespace std;
string s, scmd, tcmd, ts;
int n1,n2,fspc,sspc;
int main(){
    getline(cin,s);
    while(getline(cin,scmd) && scmd!="END")
    {
                    tcmd=scmd.substr(0,3);
                    fspc=scmd.find(" ");
                    sspc=scmd.find(" ",fspc+1);
                    if(tcmd=="ADD"){
                                    s+=scmd.substr(fspc+1,scmd.length()-fspc);
                    }else if(tcmd=="ADH"){
                          s=scmd.substr(fspc+1,scmd.length()-fspc)+s;
                    }else if(tcmd=="ERA"){
                          n1=atoi(scmd.substr(fspc+1,scmd.length()-fspc).c_str());
                          n2=atoi(scmd.substr(sspc+1,scmd.length()-sspc).c_str());
                          s=s.substr(0,n1-1)+s.substr(n2,s.length()-n2);
                    }else if(tcmd=="SUB"){
                          n1=atoi(scmd.substr(fspc+1,scmd.length()-fspc).c_str());
                          n2=atoi(scmd.substr(sspc+1,scmd.length()-sspc).c_str());
                          s=s.substr(n1-1,n2-n1+1);
                    }else if(tcmd=="SPA"){
                          n1=atoi(scmd.substr(fspc+1,scmd.length()-fspc).c_str());
                          s=s.substr(0,n1-1)+"_"+s.substr(n1-1,s.length()-n1+1);
                    }
                    cout << s << endl;
    }
    return 0;
}
