#include<iostream>
#include<string>
#include<math.h>
using namespace std;
int main(){
    string s,f,t;
    int sd, a[4];
    string n[10]={"¹s","³ü","¶L","°Ñ","¸v","¥î","³°","¬m","®Ã","¨h"};
    string n2[4]={"","¬B","¨Õ","¥a"};
    string n3[3]={"","¸U","»õ"};
    while(getline(cin,s))
    {
                         f="";
                         for(int i=0;i<s.length();i+=4)
                         {
                                 t="";
                                 sd=s.length()-1-i;
                                 a[0]=(s[sd]-48);
                                 a[1]=((sd-1>=0)?s[sd-1]-48:-1);
                                 a[2]=((sd-2>=0)?s[sd-2]-48:-1);
                                 a[3]=((sd-3>=0)?s[sd-3]-48:-1);
                                 if(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0) continue;
                                 bool bfz=false;
                                 for(int j=3;j>=0;j--)
                                 {
                                         if(a[j]!=-1)
                                         {
                                                     if(a[j]==0)
                                                     {
                                                                if(bfz==false)
                                                                {
                                                                              bool zero=false;
                                                                              for(int k=j-1;k>=0;k--) if(a[k]!=0)zero=true;
                                                                              if(zero==true){t+=n[a[j]]; bfz=true;}
                                                                }
                                                     }else{
                                                           t+=(n[a[j]]+n2[j]);
                                                     }
                                         }
                                 }
                                 f=t+n3[i/4]+f;
                         }
                         cout << f << endl;
    }
    return 0;
}
            
