#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    string s;
    scanf("%d",&n);
    getline(cin,s);
    for(int i=0;i<n;i++)
    {
            int mf=0,fm=0;
            getline(cin,s);
            int spos=0;
            while(s.find("M F",spos)!=string::npos){spos=s.find("M F",spos)+3;mf+=3;}
            spos=0;
            while(s.find("F M",spos)!=string::npos){spos=s.find("F M",spos)+3;fm+=3;}
            if( ((s[0]=='M'&&s[s.length()-1]=='F')||(s[0]=='F'&&s[s.length()-1]=='M')) && ((mf+fm+2)==s.length()) && (s.length()!=2) )
            printf("LOOP\n"); else printf("NO LOOP\n");
    }
    return 0;
}
