#include<iostream>
#include<string>
using namespace std;
string scp,s;
int n;
int main(){
    cin >> scp;
    cin >> n;
    for(int i=0;i<n;i++)
    {
            cin >> s;
            int a=0,b=0;
            for(int j=0;j<4;j++)
            {
                    for(int k=0;k<4;k++)
                    {
                            if(scp[j]==s[k])
                            { if(j==k) a++; else b++; }
                    }
            }
            cout<<a<<"A"<<b<<"B"<<endl;
    }
    return 0;
}
