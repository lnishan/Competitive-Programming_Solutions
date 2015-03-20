#include<iostream>
using namespace std;
int main(){
    int m,n;
    cin >> m;
    for(int i=1;i<=m;i++){
            cin >> n;
            cout << "Case " << i << ": " << (((n%400==0)||(n%4==0 && n%100!=0))?"a leap year":"a normal year") << endl;
    }
    return 0;
}
