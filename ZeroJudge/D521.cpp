#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
string fstr1[8]={"I\'m","\'m","he\'s","she\'s","it\'s","that\'s","what\'s","\'s"};
string fstr2[15]={"be","being","been","am","is","was","are","were","\'re","you\'re","they\'re","isn\'t","aren\'t","wasn\'t","weren\'t"};
int main(){
    string s;
    while(getline(cin,s))
    {
         for(int i=0;i<s.length();i++)s[i]=tolower(s[i]);
         int ct=0;
         for(int i=0;i<8;i++)
         {
                 int pos=0,fstrlen=fstr1[i].length();
                 while(s.find(fstr1[i],pos)!=string::npos)
                 {
                      pos=s.find(fstr1[i],pos);
                      if(pos+fstrlen==s.length()){
                           ct++;
                           string rpstr(fstrlen,'*');
                           s.replace(pos,fstrlen,rpstr);
                      }else if(!isalpha(s[pos+fstrlen]) && s.substr(pos+fstrlen+1,4)!="been"){
                           if(pos==0){
                            ct++;
                            string rpstr(fstrlen,'*');
                            s.replace(pos,fstrlen,rpstr);
                           }else if(!isalpha(s[pos-1])){
                            ct++;
                            string rpstr(fstrlen,'*');
                            s.replace(pos,fstrlen,rpstr);
                           }
                      }
                      pos+=fstrlen;
                 }
         }
         for(int i=0;i<15;i++)
         {
                 int pos=0,fstrlen=fstr2[i].length();
                 while(s.find(fstr2[i],pos)!=string::npos)
                 {
                      pos=s.find(fstr2[i],pos);
                      if(pos+fstrlen==s.length()){
                           ct++;
                           string rpstr(fstrlen,'*');
                           s.replace(pos,fstrlen,rpstr);
                      }else if(!isalpha(s[pos+fstrlen]) && s.substr(pos+fstrlen+1,4)!="been"){
                           if(pos==0){
                            ct++;
                            string rpstr(fstrlen,'*');
                            s.replace(pos,fstrlen,rpstr);
                           }else if(!isalpha(s[pos-1])){
                            ct++;
                            string rpstr(fstrlen,'*');
                            s.replace(pos,fstrlen,rpstr);
                           }
                      }
                      pos+=fstrlen;
                 }
         }
         printf("%d\n",ct);
    }
    return 0;
}
