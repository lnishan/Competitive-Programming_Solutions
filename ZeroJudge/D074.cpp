#include<iostream>
using namespace std;
int main(){
    int s,n,m=0;
    cin >> s;
    for(int i=0;i<s;i++){
            cin >> n;
            m=max(m,n);
    }
    cout << m << endl;
    return 0;
}
