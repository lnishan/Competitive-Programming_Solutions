#include<iostream>
using namespace std;
int main(){
    int ds,n,c;
    cin >> ds;
    for(int i=0;i<ds;i++)
    {
            c=0;
            cin >> n;
            c+=(n/27);
            n%=27;
            c+=(n/9);
            n%=9;
            c+=(n/3+n%3);
            cout << c << endl;
    }
    return 0;
}
