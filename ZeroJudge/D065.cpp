#include<iostream>
using namespace std;
int main(){
    int a, b, c;
    while(cin>>a>>b>>c)
                        cout << max(max(a, b),c) << endl;
    return 0;
}
