#include<iostream>
#include<math.h>
using namespace std;
string tenbin(int n);
string tenbin(int n){
       string t="";
       while(n!=1 && n!=0){t= ((n%2==1)?"1":"0") + t;n/=2;}
       t=((n==1)?"1":"")+t;
       return t;
}
int main(){
    int n;
    string s;
    while(cin>>n)
    {
                 for(int i=0;i<pow(2,n);i++)
                 {
                         s=tenbin(i);
                         if(s.length()<n)
                         {
                                         for(int j=s.length();j<n;j++) s="0"+s;
                         }
                         cout << s << endl;
                 }
    }
    return 0;
}
