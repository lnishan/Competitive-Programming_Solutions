#include<iostream>
#include<string>
using namespace std;
int n;
string s1, s2;
int main(){
    cin>>n;
    getline(cin,s1);
    for(int d=0;d<n;d++)
    {
            bool yn=true;
            getline(cin,s1);
            getline(cin,s2);
            for(int i=0;i<s1.length();i++)
            {
                    for(int j=0;j<s2.length();j++)
                    {
                            if(s1[i]==s2[j]) {s1[i]='*'; s2[j]='*'; break;}
                            if(j==s2.length()-1){yn=false; break;}
                    }
                    if(yn==false) break;
            }
            cout << ((yn==true)?"possible":"impossible") << endl;
    }
    return 0;
}
