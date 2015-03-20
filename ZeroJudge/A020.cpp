#include<iostream>
using namespace std;
int main(){
    int a[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    string s;
    while(getline(cin,s))
    {
                         int c=(a[s[0]-65]%10)*9+a[s[0]-65]/10+s[9]-48;
                         for(int i=1;i<9;i++)c+=((s[9-i]-48)*i);
                         if(c%10==0)printf("real\n");else printf("fake\n");
    }
    return 0;
}
