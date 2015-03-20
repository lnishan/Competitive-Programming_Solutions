#include<iostream>
using namespace std;
unsigned int a, b, c;
int main(){
    while(scanf("%d %d %d",&a,&b,&c) && (a!=0||b!=0||c!=0))
    {
                       while(a!=0&&b!=0) if(a>b)a%=b; else b%=a;
                       cout << ((c%((a==0)?b:a)==0)?"Yes":"No") << endl;
    }
    return 0;
}
