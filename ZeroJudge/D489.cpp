#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long int a, b, c;
    long long int s;
    while(cin>>a>>b>>c)
    {
                       s=(a+b+c)/2;
                       cout << s*(s-a)*(s-b)*(s-c) << endl;
    }
    return 0;
}
