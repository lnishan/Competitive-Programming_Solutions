#include<iostream>
using namespace std;
int main(){
    int h,m;
    while(cin>>h>>m)
                    cout << ((((h>7 && h<=17) || (h==7 && m>=30)) && (h!=17 && m!=0))?"At School":"Off School") << endl;
    return 0;
}
