#include<iostream>
using namespace std;
int main(){
    unsigned long long int a, b;
    while(cin>>a>>b)
    {
                    while (!(a==0 || b==0))
                          if (a>b)a=a%b; else b=b%a;
                    cout << ((a==0)?b*b:a*a) << endl;
    }
    return 0;
}
