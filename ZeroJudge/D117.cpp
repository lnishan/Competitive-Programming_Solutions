#include<iostream>
#include<ctype.h>
#include<math.h>
using namespace std;
int main(){
    string s;bool p;
    while(getline(cin,s))
    {
         int c=0;
         for(int i=0;i<s.length();i++)
                 if(isupper(s[i]))c+=(s[i]-38);else c+=(s[i]-96);
         if(c%2==0&&c!=2)
                   p=false;
         else
         {
             p=true;
             for(int i=3;i<=sqrt(c);i+=2)
                     if(c%i==0&&c!=i){p=false;break;}
         }
         if(p)printf("It is a prime word.\n");else printf("It is not a prime word.\n");
    }
    return 0;
}
