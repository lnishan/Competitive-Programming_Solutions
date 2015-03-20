#include<iostream>
using namespace std;
string s[100000];
int main(){
    int n;
    scanf("%d",&n);
    getline(cin,s[0]);
    for(int i=0;i<n;i++)getline(cin,s[i]);
    sort(s,s+n);
    for(int i=0;i<n;i++)cout<<s[i]<<endl;
    system("pause");
    return 0;
}
