#include<iostream>
using namespace std;
int n, a, b, c;
int main(){
    cin >> n;
    for(int i=0; i<n; i++)
    {
            cin>>a>>b>>c;
            if(a!=b && b!=c && c!=a) cout << "YES" << endl;
            else cout << "NO" << endl;
    }
    return 0;
}
