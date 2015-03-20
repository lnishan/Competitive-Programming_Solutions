#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int k;
    while(cin>>k>>s)
    {
                    int c=0;
                    for(int i=1;i<s.length()-k;i++)
                    {
                                         for(int j=1;j<=i;j++)
                                                 if(s.substr(i-j,j)==s.substr(i+k,j)) c++;
                    }
                    cout << c << endl;
    }
    return 0;
}
