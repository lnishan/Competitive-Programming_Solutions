#include<iostream>
using namespace std;
int main(){
    long long int a, b;
    while(cin>>a>>b)
    {
                    if(a>b) {a=a+b; b=a-b; a-=b;}
                    a=((a%2==0)?a:a+1);
                    b=((b%2==0)?b:b-1);
                    cout << (a+b)*((b-a)/2+1)/2 << endl;
    }
    return 0;
}
