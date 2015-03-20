#include<iostream>
using namespace std;
int main(){
    int a, b, c, t, pt=0;
    while(cin>>a>>b>>c)
    {
                  if(a>b){t=a;a=b;b=t;}
                  if(b>c){t=b;b=c;c=t;}
                  if(a>b){t=a;a=b;b=t;}
                  if(a+b>c) pt++;
    }
    cout << pt;
    return 0;
}
