#include<iostream>
#include<string>
#include<math.h>
#include<ctype.h>
#include<iomanip>
using namespace std;
int main(){
    string s;
    while(getline(cin,s))
    {
                         if(s.find("i")==string::npos)
                         {
                                                      cout<<fixed<<setprecision(3)<<double(abs(atoi(s.c_str())))<<endl;
                         }else{
                               long int c,t,a[2]={0,1};
                               for(int i=0;i<s.length();i++)
                               {
                                       if(isdigit(s[i]))
                                       {
                                                        t=s[i]-48;
                                                        for(int j=i+1;;j++)
                                                        {
                                                                if(isdigit(s[j]))
                                                                {
                                                                                 t=t*10+s[j]-48;
                                                                }else{
                                                                      if(s[j]=='i')c=1;else c=0;
                                                                      a[c]=t;
                                                                      i=j-1;break;
                                                                }
                                                        }
                                       }
                               }
                               cout<<fixed<<setprecision(3)<<sqrt(a[0]*a[0]+a[1]*a[1])<<endl;
                         }
    }
    return 0;
}
