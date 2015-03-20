#include<iostream>
#include<string>
using namespace std;
int main(){
    int ds,n;
    string s;
    cin >> ds;
    for(int i=0;i<ds;i++)
    {
            cin >> n >> s;
            for(int j=0;j<s.length();j++)
                    s[j]=((s[j]-n<65)?s[j]-n+26:s[j]-n);
            cout << s << endl;
    }
    return 0;
}
