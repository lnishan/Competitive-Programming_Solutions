#include<iostream>
#include<string>
#include<queue>

using namespace std;

queue<string> q;

string a[83682];
int main(){
    int sl,ct=0,result;
    string s="a",ts,ss;
    for(int i=0;i<26;i++){q.push(s);s[0]++;}
    while(1)
    {
            s=q.front();
            sl=s.length();
            if(sl==5)break;
            a[++ct]=s;
            q.pop();
            for(int i=s[sl-1]+1;i<=122;i++)
            {
                    ts=s+char(i);
                    q.push(ts);
            }
    }
    while(!q.empty()){a[++ct]=q.front();q.pop();}
    while(getline(cin,ss))
    {
          result=0;
          for(int i=1;i<=ct;i++)
                  if(a[i]==ss){result=i;break;}
          printf("%d\n",result);
    }
    return 0;
}
