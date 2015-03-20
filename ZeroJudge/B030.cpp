#include<iostream>
#include<string>
using namespace std;
int n;
string s1, s2;
int main(){
    while(getline(cin,s1),getline(cin,s2))
    {
            bool yn=true;
            for(int i=0;i<s1.length();i++)
            {
                    for(int j=0;j<s2.length();j++)
                    {
                            if(s1[i]==s2[j]) {s1[i]='*'; s2[j]='*'; break;}
                            if(j==s2.length()-1){yn=false; break;}
                    }
                    if(yn==false) break;
            }
            cout << ((yn==true)?"Yes":"No") << endl;
    }
    return 0;
}
