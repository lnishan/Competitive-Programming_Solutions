#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
using namespace std;
int main(){
    string s;bool to10;
    int a[103];
    a[48]=0;a[49]=1;a[50]=2;a[51]=3;a[52]=4;a[53]=5;a[54]=6;a[55]=7;a[56]=8;a[57]=9;a[65]=10;a[66]=11;a[67]=12;a[68]=13;a[69]=14;a[70]=15;
    while(getline(cin,s)&&s[0]!='-')
    {
                         if(s.length()>2)
                                         if(s.substr(0,2)=="0x")to10=true;else to10=false;
                         else
                             to10=false;
                         if(to10)
                         {
                                 long int r=0,t16=1,sl=s.length()-2;
                                 s=s.substr(2,s.length()-2);
                                 for(int i=0;i<sl;i++){r+=(a[s[sl-i-1]]*t16);t16*=16;}
                                 printf("%d\n",r);
                         }else
                               cout<<"0x"<<uppercase<<hex<<atoi(s.c_str())<<endl;
    }
    return 0;
}
