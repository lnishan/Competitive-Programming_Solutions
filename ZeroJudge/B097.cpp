#include<iostream>
using namespace std;
int n;
int main(){
    long int a, b, c, d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>c>>d;
            a=c;
            b=d;
            while(a!=0 && b!=0) if(a>b) a%=b; else b%=a;
            cout << c*d/((a==0)?b:a) << endl;
    }
    return 0;
}
