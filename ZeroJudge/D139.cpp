#include<iostream>
#include<string>
using namespace std;
string s,s2;
char ll;
string cstr(int no);
string cstr(int no){
       string f="";
       char c;
       while(no!=0)
       {
              c=(no%10+48);
              f=c+f;
              no=(no-no%10)/10;
       }
       return f;
}
int main(){
    while(getline(cin,s))
    {
                         s2="";
                         ll=s[0];
                         int c=1,pos=0;
                         for(int i=1;i<s.length();i++)
                         {
                                 if(s[i]==ll){c++;
                                 }else{
                                      if(c==1){s2+=s[i-1];}else{s2+=(cstr(c)+s[i-1]);c=1;}
                                 }
                                 ll=s[i];
                         }
                         if(c==1){s2+=s[s.length()-1];}else{s2+=(cstr(c)+s[s.length()-1]);}
                         while(s2.find("2",pos)!=string::npos)
                         {
                                                              pos=s2.find("2",pos)+1;
                                                              if((s2[pos-2]>57||s2[pos-2]<48)&&(s2[pos]>57||s2[pos]<48))s2[pos-1]=s2[pos];
                         }
                         cout<<s2<<endl;
    }
    return 0;
}
