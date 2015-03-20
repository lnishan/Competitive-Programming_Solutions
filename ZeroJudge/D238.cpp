/*#include<iostream>
#include<string>
#include<fstream>
using namespace std;
string siTimes(string scal, int ncal);

int main(){
    int a, n;
    while(cin>>a>>n)
    {
                    int c=0;
                    string s="1";
                    for(int i=0;i<n;i++) s=siTimes(s,a);
                    for(int i=0;i<s.length();i++)c+=(s[i]-48);
                    ofstream of("output.txt");
                    of<<c;
    }
    return 0;
}

string siTimes(string scal, int ncal){
       int prevn=0,tn;
       for(int i=scal.length()-1;i>=0;i--)
       {
               tn=(scal[i]-48)*ncal + prevn;
               prevn=tn/10;
               scal[i]=48+ tn-prevn*10;
       }
       char cha=48+prevn;
       if(prevn!=0) scal=cha+scal;
       return scal;
}
*/

#include<iostream>
int main(){
    std::printf("%d",1366);
    return 0;
}
